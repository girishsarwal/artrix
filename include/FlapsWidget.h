#pragma once
#include "artrix-includes.h"
class FlapsWidget : public Widget{
private:
	int m_iPosition;
public:
	void onGetValuesFromSensors();
	void onUpdate();
	void onRender();
};
