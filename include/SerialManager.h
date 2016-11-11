#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H
#include <string>
#include "afx.h"
class SerialManager{
private:
	std::string m_pPortName;
	uint m_iBaudRate;
	uint m_iDataBits;
    uint m_iParity;
    static SerialManager* m_pInstance;
    SerialManager();

public:
	bool initialize(const std::string&);
	void shutdown();
	static SerialManager* getInstance();
	~SerialManager();
};
#define RS232M SerialManager::getInstance()
#endif
