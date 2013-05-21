/*
 * TextWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		modified: girish
 */

#pragma once

#include "afx.h"

class TextWidget: public UIWidget {
protected:
	void onInitialize();
	void onRender(double frameTime);
public:
	std::string	m_pText;
	std::string m_pFont;
	std::string m_pSize;
	
	TextWidget();
	TextWidget(AttributeSet& attrs);
	virtual ~TextWidget();
};


