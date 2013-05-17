/*
 * TextWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 */

#pragma once

#include "afx.h"

class TextWidget: public UIWidget {
private:
	std::string	m_pText;
	std::string m_pFont;
	std::string m_pSize;
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


