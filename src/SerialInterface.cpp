#include "afx.h"

SerialInterface::SerialInterface(){
	m_pPortName = "dev/ttyS0";			/** Read from settings **/
	m_iBaudRate = 9600;
	m_iParity = 0;
};

SerialInterface::~SerialInterface(){
};


void SerialInterface::openPort(){
	int fd;
	fd = open(m_pPortName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
	if (fd == -1){
		printf("WARNING: port open for '%s' failed. port will not be available\n", m_pPortName.c_str());
		return;
	}
	printf("Port '%s' opened successfully\n", m_pPortName.c_str());
};
