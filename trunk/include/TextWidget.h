/*
 * TextWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 */

#pragma once

#include "afx.h"

class TextWidget: public Widget {
private:
	std::string	m_pText;
	int m_iSize;
	unsigned long long m_fBackground;
	
protected:
	void onInitialize();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
public:
	TextWidget();
	TextWidget(AttributeSet& attrs);
	virtual ~TextWidget();
};


