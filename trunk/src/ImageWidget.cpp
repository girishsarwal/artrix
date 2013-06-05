/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "afx.h"
void ImageWidget::onInitialize(){
	m_pPath = m_asAttributes.get("src").getValue().c_str();
	m_iTextureId = TM->getTexture(m_pPath);
}
ImageWidget::ImageWidget() {

}

ImageWidget::~ImageWidget() {
	
};


void ImageWidget::onUpdate(double frameTime){
	
};

void ImageWidget::onRender(double frameTime){
	glColor4ub((m_fBackground & 0x00FF0000) >> 0x10,
				(m_fBackground & 0x0000FF00) >> 0x08,
				m_fBackground & 0x000000FF,
				(m_fBackground & 0xFF000000) >> 0x18);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_iTextureId);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0, 0.0);
		glVertex3f(m_vPosition.x - m_vHalfSize.x, m_vPosition.y - m_vHalfSize.y, 0);
		
		glTexCoord2f(1.0, 0.0);
		glVertex3f(m_vPosition.x + m_vHalfSize.x, m_vPosition.y - m_vHalfSize.y, 0);
		
		glTexCoord2f(1.0, 1.0);
		glVertex3f(m_vPosition.x + m_vHalfSize.x, m_vPosition.y + m_vHalfSize.y, 0);
		
		glTexCoord2f(0.0, 1.0);
		glVertex3f(m_vPosition.x - m_vHalfSize.x, m_vPosition.y + m_vHalfSize.y, 0);
	};
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
