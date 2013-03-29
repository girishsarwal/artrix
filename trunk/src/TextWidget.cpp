/*
 * TextWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 */

#include "afx.h"
TextWidget::TextWidget(AttributeSet& attrs){
	TextWidget();
	m_vPosition.x = atof(attrs.get("x").getValue().c_str());
	m_vPosition.y = atof(attrs.get("y").getValue().c_str());
	m_vSize.x = atof(attrs.get("width").getValue().c_str());
	m_vSize.y = atof(attrs.get("height").getValue().c_str());
	
	m_fBackground = strtoll(attrs.get("background").getValue().c_str(), NULL, 16);
	
	m_pText = attrs.get("text").getValue().c_str();
	m_pFont = attrs.get("font").getValue().c_str();
	m_pSize = attrs.get("size").getValue().c_str();
	
}
TextWidget::TextWidget() {
	m_pSize = std::string("medium");
	m_pText= "No Text";
}

TextWidget::~TextWidget() {
	
}

void TextWidget::onInitialize(){
	
}

void TextWidget::onUpdate(double frameTime){
}

void TextWidget::onRender(double frameTime){
	glPushMatrix();
	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
	glColor3f(1.0, 0.0, 0.0);
	
	glEnable(GL_TEXTURE_2D);
	FM->setActiveFont(m_pFont, m_pSize);
	glListBase(0);
	glCallLists(5, GL_BYTE, "b");
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

