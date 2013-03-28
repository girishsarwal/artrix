#pragma once
#include "afx.h"
class SerialInterface{
private:
	std::string m_pPortName;
	uint m_iBaudRate;
	uint m_iDataBits;
    uint m_iParity;
public:
	void openPort();
	void close();
	SerialInterface();
	~SerialInterface();
};
