#pragma once
#include "afx.h"
class Widget
{
public:
	Vector m_vPosition;
	Vector m_vSize;
	bool m_bInitialized;
	
	void initialize();
	void update(double frameTime);
	void getValuesFromSensors();
	void render(double frameTime);


	void setDrawRectangle(float _left, float _top, float _width, float _height);
	Widget(void);
	~Widget(void);

protected:
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onGetValuesFromSensors();
	virtual void onRender(double frameTime);
};

