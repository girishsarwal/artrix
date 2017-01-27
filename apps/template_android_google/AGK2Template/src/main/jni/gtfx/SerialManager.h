#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H
#include "afx.h"
namespace gtfx {
class SerialManager{
private:
	std::string m_pPortName;
	uint m_iDataBits;
    uint m_iParity;
	uint m_iBaudRate;
    static SerialManager* m_pInstance;
    SerialManager();

public:
	bool initialize(const std::string&);
	void shutdown();
	static SerialManager* GetInstance();
	~SerialManager();
};
}
#endif
