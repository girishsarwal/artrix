#include "SPIManager.h"

SPIManager::SPIManager(){
	m_pPortName = "/dev/spidev0.0";			/** TOOD: Read from settings **/
	m_iBaudRate = 9600;
	m_iParity = 0;
	
};

SPIManager::~SPIManager(){
};

bool SPIManager::initialize(const std::string& root){
	m_pPortName = root;
	printf("+--------------------SPI MANAGER----------------------+\n");
	printf("Initializing from %s\n", m_pPortName.c_str());
	int fd;
	fd = open(m_pPortName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
	if (fd == -1){
		printf("WARNING: port open for '%s' failed.  Cannot connect to gt-jtx.\n\n ***Realtime updates will be unavailable***\n\n", m_pPortName.c_str());
		return true;
	}
	printf("Port '%s' opened successfully\n", m_pPortName.c_str());
	return true;
};
void SPIManager::shutdown(){
	
}


SPIManager* SPIManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new SPIManager();
	}
	return m_pInstance;
}

SPIManager* SPIManager::m_pInstance = NULL;





