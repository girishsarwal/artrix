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
	m_pText = m_asAttributes.get("text").getValue().c_str();
	m_pFont = m_asAttributes.get("font").getValue().c_str();
	m_pSize = m_asAttributes.get("size").getValue().c_str();
	m_bIsBold = atoi(m_asAttributes.get("bold").getValue().c_str());
	m_fColor = atoll(m_asAttributes.get("color").getValue().c_str());
};

void TextWidget::onRender(double frameTime){
	/*glColor4ub((m_fColor & 0x00FF0000) >> 0x10,
				(m_fColor & 0x0000FF00) >> 0x08,
				m_fColor & 0x000000FF,
				(m_fColor & 0xFF000000) >> 0x18);*/
	printf("Rendering TextWidget\n");
	glTranslatef(m_vPosition.x, m_vPosition.y, 1);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	FM->setActiveFont(m_pFont, m_pSize, m_bIsBold);
	glCallLists(m_pText.length(), GL_BYTE, m_pText.c_str());
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
};

void TextWidget::onUpdate(double frameTime){
};

