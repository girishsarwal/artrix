#pragma once
#include "afx.h"
class SerialInterface{
private:
	std::string m_pPortName;
	uint m_iBaudRate;
	uint m_iDataBits;
    uint m_iParity;
    static SerialInterface* m_pInstance;
	SerialInterface();

public:
	void initialize();
	void shutdown();
	static SerialInterface* getInstance();
	~SerialInterface();
};