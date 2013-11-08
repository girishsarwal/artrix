/*
 * TextWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		Modified: girish
 */

#include "afx.h"
TextWidget::TextWidget() {
	m_pSize = 10;
	m_pText= "No Text";
}

TextWidget::~TextWidget() {
	
}

void TextWidget::onInitialize(){
	m_pText = m_asAttributes.get("text").getValue().c_str();
	m_pFont = m_asAttributes.get("font").getValue().c_str();
	m_pSize = atof(m_asAttributes.get("size").getValue().c_str());
	m_bIsBold = atoi(m_asAttributes.get("bold").getValue().c_str());
	m_fColor = strtoll(m_asAttributes.get("color").getValue().c_str(), NULL, 16);
};

void TextWidget::onRender(double frameTime){
	glColor4ub((m_fColor & 0x00FF0000) >> 0x10,
				(m_fColor & 0x0000FF00) >> 0x08,
				m_fColor & 0x000000FF,
				(m_fColor & 0xFF000000) >> 0x18);
	glTranslatef(m_vPosition.x, m_vPosition.y, 1);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	//FM->setActiveFont(m_pFont, m_pSize, m_bIsBold);
	//uint id = TM->getTexture(m_pFont);
	glBindTexture(GL_TEXTURE_2D, TM->getTexture(m_pFont));
	//glListBase(-32);
	glScalef(m_pSize/10.0, m_pSize/10.0, 1);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glCallLists(m_pText.length(), GL_BYTE, m_pText.c_str());
	glDisable(GL_BLEND);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
};

void TextWidget::onUpdate(double frameTime){
};

