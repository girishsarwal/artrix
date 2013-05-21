/*
 * TextWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		Modified: girish
 */

#include "afx.h"
TextWidget::TextWidget() {
	m_pSize = std::string("medium");
	m_pText= "No Text";
}

TextWidget::~TextWidget() {
	
}

void TextWidget::onInitialize(){
	UIWidget::onInitialize();
	m_pText = m_asAttributes.get("text").getValue().c_str();
	m_pFont = m_asAttributes.get("font").getValue().c_str();
	m_pSize = m_asAttributes.get("size").getValue().c_str();
	
}

void TextWidget::onRender(double frameTime){
	glPushMatrix();
	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	FM->setActiveFont(m_pFont, m_pSize);
	glListBase(-31);
	glCallLists(m_pText.length(), GL_BYTE, m_pText.c_str());
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopAttrib();
	UIWidget::onRender(frameTime);
}

