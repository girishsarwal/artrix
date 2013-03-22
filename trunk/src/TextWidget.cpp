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
	m_iSize = atoi(attrs.get("size").getValue().c_str());
}
TextWidget::TextWidget() {
	m_iSize = 10;
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
	glTranslatef(m_vPosition.x, m_vPosition.y, 50);
	float scaleFactor = 0.001F * m_iSize;
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	glColor3f(0, 0, 0);
	int index = -1;
	
	while(++index < m_pText.length()){
		printf("%c", m_pText.at(index));
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, m_pText.at(index));
	}
	glPopMatrix();
}

