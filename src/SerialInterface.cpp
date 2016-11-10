#include "afx.h"

SerialInterface::SerialInterface(){
	m_pPortName = "/dev/ttyS0";			/** Read from settings **/
	m_iBaudRate = 9600;
	m_iParity = 0;
};

SerialInterface::~SerialInterface(){
};

bool SerialInterface::initialize(const string& root){
	m_pPortName = root;
	printf("+--------------------RS232 SERIAL MANAGER----------------------+\n");
	printf("Initializing from %s\n", m_pPortName.c_str());

	int fd;
	fd = open(m_pPortName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
	if (fd == -1){
		printf("WARNING: port open for '%s' failed.  Cannot connect to gt-jtx.\n\n ***Realtime updates will be unavailable***\n\n", m_pPortName.c_str());
		return false;
	}
	printf("Port '%s' opened successfully\n", m_pPortName.c_str());
	return true;
	
};
void SerialInterface::shutdown(){
	
}


SerialInterface* SerialInterface::getInstance(){
	if(!m_pInstance){
		m_pInstance = new SerialInterface();
	}
	return m_pInstance;
}

SerialInterface* SerialInterface::m_pInstance = NULL;





