/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "afx.h"
ImageWidget::ImageWidget(AttributeSet& attrs){
	ImageWidget();
	m_vPosition.x = atof(attrs.get("x").getValue().c_str());
	m_vPosition.y = atof(attrs.get("y").getValue().c_str());
	m_vSize.x = atof(attrs.get("width").getValue().c_str());
	m_vSize.y = atof(attrs.get("height").getValue().c_str());
	
	m_fBackground = strtoll(attrs.get("background").getValue().c_str(), NULL, 16);
	
	m_pPath = attrs.get("src").getValue().c_str();
}
ImageWidget::ImageWidget() {

}

ImageWidget::~ImageWidget() {
	
}

void ImageWidget::onInitialize(){
	m_iTextureId = TM->getTexture(m_pPath);
}

void ImageWidget::onUpdate(double frameTime){
}

void ImageWidget::onRender(double frameTime){
	glColor4ub((m_fBackground & 0x00FF0000) >> 0x10,
				(m_fBackground & 0x0000FF00) >> 0x08,
				m_fBackground & 0x000000FF,
				(m_fBackground & 0xFF000000) >> 0x18);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_iTextureId);
	
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0, 0.0);
		glVertex3f(m_vPosition.x, m_vPosition.y, 0);
		
		glTexCoord2f(1.0, 0.0);
		glVertex3f(m_vPosition.x + m_vSize.x, m_vPosition.y, 0);
		
		glTexCoord2f(1.0, 1.0);
		glVertex3f(m_vPosition.x + m_vSize.x, m_vPosition.y + m_vSize.y, 0);
		
		glTexCoord2f(0.0, 1.0);
		glVertex3f(m_vPosition.x, m_vPosition.y + m_vSize.y, 0);
		
	};
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
