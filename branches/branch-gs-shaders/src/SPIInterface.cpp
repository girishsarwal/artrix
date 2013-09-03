#include "afx.h"

SPIInterface::SPIInterface(){
	m_pPortName = "/dev/spidev0.0";			/** Read from settings **/
	m_iBaudRate = 9600;
	m_iParity = 0;
	
};

SPIInterface::~SPIInterface(){
};

void SPIInterface::initialize(){
	int fd;
	fd = open(m_pPortName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
	if (fd == -1){
		printf("WARNING: port open for '%s' failed.  Cannot connect to gt-jtx.\n\n ***Realtime updates will be unavailable***\n\n", m_pPortName.c_str());
		return;
	}
	printf("Port '%s' opened successfully\n", m_pPortName.c_str());
	
};
void SPIInterface::shutdown(){
	
}


SPIInterface* SPIInterface::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new SPIInterface();
	}
	return m_pInstance;
}

SPIInterface* SPIInterface::m_pInstance = NULL;





