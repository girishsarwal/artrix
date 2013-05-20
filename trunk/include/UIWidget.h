/*
 * UIWidget.h.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once

#include "afx.h"

class UIWidget : public Widget {
private:
	unsigned long long m_fBackground;
protected:
	
	void render(double frameTime);
	virtual void setDrawRectangle(float _left, float _top, float _width, float _height);
	
public:
	Vector m_vPosition;
	Vector m_vSize;
	UIWidget();
	virtual ~UIWidget();
	void onInitialize();
};


