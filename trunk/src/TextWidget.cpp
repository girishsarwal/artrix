/*
 * TextWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 */

#include "afx.h"
TextWidget::TextWidget() {
	m_pSize = std::string("medium");
	m_pText= "No Text";
}

TextWidget::~TextWidget() {
	
}

void TextWidget::onInitialize(){
	m_vPosition.x = atof(m_asAttributes.get("x").getValue().c_str());
	m_vPosition.y = atof(m_asAttributes.get("y").getValue().c_str());
	m_vSize.x = atof(m_asAttributes.get("width").getValue().c_str());
	m_vSize.y = atof(m_asAttributes.get("height").getValue().c_str());
	
	m_fBackground = strtoll(m_asAttributes.get("background").getValue().c_str(), NULL, 16);
	
	m_pText = m_asAttributes.get("text").getValue().c_str();
	m_pFont = m_asAttributes.get("font").getValue().c_str();
	m_pSize = m_asAttributes.get("size").getValue().c_str();
}

void TextWidget::onUpdate(double frameTime){
}

void TextWidget::onRender(double frameTime){
	glPushMatrix();
	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
	glColor3f(1.0, 0.0, 0.0);
	
	glEnable(GL_TEXTURE_2D);
	FM->setActiveFont(m_pFont, m_pSize);
	//glListBase(FM->getActiveFontBase() -54);
	glCallLists(1, GL_BYTE, "a");
	/*glBegin(GL_QUADS);
			{
				glTexCoord2f(0, 0);
				glVertex2f(-25,-25);
				glTexCoord2f(0, 1);
				glVertex2f(-25, 25);
				glTexCoord2f(1, 1);
				glVertex2f( 25, 25);
				glTexCoord2f(1, 0);
				glVertex2f( 25,-25);
			};
	glEnd();*/
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

