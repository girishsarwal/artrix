#include <stdio.h>
#include <fcntl.h> 
#include <time.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include <glib.h>
#include <memory.h>


typedef struct connection_t{
	char* port;
	int baudrate;
	char* parity;
	int stopbits;
	int fd;
};

char frame[11];		/**frsky proto has 11 bytes per frame **/

typedef struct telemetry_t{
};

connection_t *connection;
telemetry_t *telemetry;

bool openSerialInterface();
void closeSerialInterface();
bool readConfig(char * configFile);
void createDummyFrame();

int main(int argc, char* argv[]){
	if(argv[1] == NULL){
		printf("USAGE: frsky-emu <config-file-absolute-path> \n");
		return -1;
	};
	printf("\n\nFRSKY EMULATOR\n");
	printf("----ver 1.0---\n");
	
	if(!readConfig(argv[1])){
		return -1;
	};
	
	if(!openSerialInterface()){
		return -1;
	};
	printf("OK Started. Attach client. Bit Banging now...Hit Ctrl + C to exit\n");

	int x = 0;
	while(true){
		createDummyFrame();
		write(connection->fd, frame, 11);
	};
	closeSerialInterface();
	return 0;
};
bool readConfig(char* configFile){
	GKeyFile* pFile = g_key_file_new();
	
	printf("Attempting to read configuration from %s\n", configFile);
	if(!g_key_file_load_from_file(pFile, configFile, (GKeyFileFlags)(G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS), 0)){
		printf("ERROR: Cannot find config file\n");
		return false;
	};
	if(NULL == pFile){
		printf("ERROR: Cannot load config file\n");
		return false;
	};
	connection = g_slice_new(connection_t);
	
	connection->port = g_key_file_get_string(pFile, "connect", "port", 0);
	connection->baudrate = g_key_file_get_integer(pFile, "connect", "baudrate", 0);
	connection->parity = g_key_file_get_string(pFile, "connect", "parity", 0);
	connection->stopbits = g_key_file_get_integer(pFile, "connect", "stopbits", 0);
	
	printf("Setting up %s with:\n\n", connection->port);
	printf("Baud Rate %d\n", connection->baudrate);
	printf("Parity %s\n", connection->parity);
	printf("Stop Bits %d\n", connection->stopbits);
	
	return true;
};
bool openSerialInterface(){
	int baudrate;
	int parity = 0;
	
	connection->fd = open(connection->port, O_RDWR | O_NOCTTY | O_SYNC);
	if (connection->fd == -1){
		printf("ERROR: port open for '%s' failed.\n", connection->port);
		return false;
	}
	printf("Port '%s' opened successfully\n", connection->port);
	termios tty;
	memset(&tty, 0, sizeof(termios));
	if(tcgetattr(connection->fd, &tty) != 0){
		printf("ERROR: cannot get parameters for '%s'.\n", connection->port);
		return false;
	};
	cfsetospeed(&tty, B9600);
	cfsetispeed(&tty, B9600);
	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // ignore break signal
    tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (connection->fd, TCSANOW, &tty) != 0)
    {
		printf("error %d from tcsetattr", errno);
		return false;
    }
    return true;
};

void createDummyFrame(){
	memset(frame, 0x5E, 1);
	memset(frame + 10, 0x5E, 1);
};
void closeSerialInterface(){
};
