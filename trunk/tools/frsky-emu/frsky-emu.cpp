

#include <stdio.h>
#include <fcntl.h> 
#include <time.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include <glib.h>


typedef struct connection_t{
	char* port;
	int baudrate;
	char* parity;
	int stopbits;
};

typedef struct telemetry_t{
};

connection_t *connection;
telemetry_t *telemetry;

void openSerialInterface();
void closeSerialInterface();

bool readConfig(char * configFile);
int main(int argc, char* argv[]){
	if(argv[1] == NULL){
		printf("Usage: frsky-emu <config-file-absolute-path> \n");
		return -1;
	};
	printf("\n\nFRSKY EMULATOR\n");
	printf("----ver 1.0---\n");
	
	if(!readConfig(argv[1])){
		return -1;
	};
	
	openSerialInterface();
	closeSerialInterface();
	
	printf("OK Started. Attach client. Bit Banging now...\n");
	
	while(true){


	};
	closeSerialInterface();
	return 0;
};
bool readConfig(char* configFile){
	GKeyFile* pFile = g_key_file_new();
	
	printf("Attempting to read configuration from %s\n", configFile);
	if(!g_key_file_load_from_file(pFile, configFile, (GKeyFileFlags)(G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS), 0)){
		printf("Error: Cannot find config file\n");
		return false;
	};
	if(NULL == pFile){
		printf("Error: Cannot load config file\n");
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
void openSerialInterface(){
	int fd;
	fd = open(connection->port, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd == -1){
		printf("WARNING: port open for '%s' failed.  Cannot connect to gt-jtx.\n\n ***Realtime updates will be unavailable***\n\n", connection->port);
		return;
	}
	printf("Port '%s' opened successfully\n", connection->port);
};
void closeSerialInterface(){
};
