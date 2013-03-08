#pragma once
#include "afx.h"
class Widget
{
public:
	/** widget rectangle **/
	float left;
	float top;
	float width;
	float height;

	void update();
	void getValuesFromSensors();
	void render();


	void setDrawRectangle(float _left, float _top, float _width, float _height);
	Widget(void);
	~Widget(void);

protected:
	virtual void onUpdate();
	virtual void onGetValuesFromSensors();
	virtual void onRender();
};

