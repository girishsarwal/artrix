#pragma once
#include "afx.h"
class SPIInterface{
private:
/**
 * { "device",  1, 0, 'D' },
			{ "speed",   1, 0, 's' },
			{ "delay",   1, 0, 'd' },
			{ "bpw",     1, 0, 'b' },
			{ "loop",    0, 0, 'l' },
			{ "cpha",    0, 0, 'H' },
			{ "cpol",    0, 0, 'O' },
			{ "lsb",     0, 0, 'L' },
			{ "cs-high", 0, 0, 'C' },
			{ "3wire",   0, 0, '3' },
			{ "no-cs",   0, 0, 'N' },
			{ "ready",   0, 0, 'R' },
			{ NULL, 0, 0, 0 },
			* */
	std::string m_pPortName;
	uint m_iBaudRate;
	uint m_iDataBits;
    uint m_iParity;
    
    
    std::string m_pdevice;
	uint8_t m_eMode;
	uint8_t m_uiBits;
	uint32_t m_ui32Speed;
	uint16_t m_ui16Delay;


    static SPIInterface* m_pInstance;
	SPIInterface();

public:
	bool initialize(const string&);
	void shutdown();
	static SPIInterface* getInstance();
	~SPIInterface();
};
