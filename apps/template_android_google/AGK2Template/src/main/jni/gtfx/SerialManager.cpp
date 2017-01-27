#include "SerialManager.h"
namespace gtfx {
SerialManager::SerialManager()
	: m_pPortName ("/dev/ttyS0")
	, m_iBaudRate (9600)
	, m_iParity (0)
	, m_iDataBits (0) {

};

SerialManager::~SerialManager(){
};

bool SerialManager::initialize(const std::string& root){
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
void SerialManager::shutdown(){
	
}


SerialManager* SerialManager::GetInstance(){
	if(!m_pInstance){
		m_pInstance = new SerialManager();
	}
	return m_pInstance;
}

SerialManager* SerialManager::m_pInstance = NULL;
}
