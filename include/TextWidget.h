/*
 * TextWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		modified: girish
 */

#pragma once
#include "afx.h"
#include "UIWidget.h"
class TextWidget: public UIWidget {
protected:
	void onInitialize();
	void onRender(double frameTime);
	void onUpdate(double frameTime);
public:
	std::string	m_pText;
	std::string m_pFont;
	float m_pSize;
	unsigned long long m_fColor;			
		

	bool m_bIsBold;
	TextWidget();
	TextWidget(tinyxml2::XMLNode*);
	virtual ~TextWidget();
};


