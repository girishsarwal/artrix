#pragma once
#include "afx.h"
class FlapsWidget : public Widget{
private:
	int m_iPosition;
public:
	void onGetValuesFromSensors();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
};
