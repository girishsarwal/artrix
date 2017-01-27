#ifndef FLAPSWIDGET_H
#define FLAPSWIDGET_H
#include "afx.h"
#include "UIWidget.h"
class FlapsWidget
		: public gtfx::UIWidget{
private:
	int m_iPosition;
public:
	void onGetValuesFromSensors();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
};
#endif
