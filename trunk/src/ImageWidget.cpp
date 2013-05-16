/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "afx.h"
void ImageWidget::onInitialize(){
	m_vPosition.x = atof(m_asAttributes.get("x").getValue().c_str());
	m_vPosition.y = atof(m_asAttributes.get("y").getValue().c_str());
	m_vSize.x = atof(m_asAttributes.get("width").getValue().c_str());
	m_vSize.y = atof(m_asAttributes.get("height").getValue().c_str());
	
	m_fBackground = strtoll(m_asAttributes.get("background").getValue().c_str(), NULL, 16);
	
	m_pPath = m_asAttributes.get("src").getValue().c_str();
	m_iTextureId = TM->getTexture(m_pPath);
	printf("Texture Pick %d", m_iTextureId);
}
ImageWidget::ImageWidget() {

}

ImageWidget::~ImageWidget() {
	
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
