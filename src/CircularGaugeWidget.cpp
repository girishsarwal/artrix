/*
 * CircularGaugeWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		Modified: girish
 */

#include "CircularGaugeWidget.h"
CircularGaugeWidget::CircularGaugeWidget() {
	
};

CircularGaugeWidget::CircularGaugeWidget(tinyxml2::XMLNode* node){
	
};

CircularGaugeWidget::~CircularGaugeWidget() {
	
};

void CircularGaugeWidget::onInitialize(){
//	std::string sDialTexture;
//	std::string sNeedleTexture;
//
//	sDialTexture = m_asAttributes.get("gaugeBg").getValue().c_str();
//	sNeedleTexture = m_asAttributes.get("needleBg").getValue().c_str();
//
//	m_iDialTextureId = TM->getTexture(sDialTexture);
//	m_iNeedleTextureId = TM->getTexture(sNeedleTexture);
//
//	m_vNeedleSize.x = atof(m_asAttributes.get("needleWidth").getValue().c_str());
//	m_vNeedleSize.y = atof(m_asAttributes.get("needleHeight").getValue().c_str());
//	m_vNeedleSize.Scale(0.5);
//
//	m_dMin = atof(m_asAttributes.get("min").getValue().c_str());
//	m_dMax = atof(m_asAttributes.get("max").getValue().c_str());
//	m_dRange = m_dMax - m_dMin;
//
//	m_dValue = atof(m_asAttributes.get("value").getValue().c_str());
//
//	m_dGaugeMax = atof(m_asAttributes.get("gaugeMax").getValue().c_str());
//	m_dGaugeMin = atof(m_asAttributes.get("gaugeMin").getValue().c_str());
//	m_dGaugeRange = m_dGaugeMax == 360 ? 360 : 360 - (m_dGaugeMax - m_dGaugeMin);
};

void CircularGaugeWidget::onRender(double frameTime){
//	glColor4ub((m_fBackground & 0x00FF0000) >> 0x10,
//				(m_fBackground & 0x0000FF00) >> 0x08,
//				m_fBackground & 0x000000FF,
//				(m_fBackground & 0xFF000000) >> 0x18);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, m_iDialTextureId);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	glTranslatef(m_vPosition.x, m_vPosition.y, m_vPosition.z);
//	glScalef(m_vHalfSize.x, m_vHalfSize.y, 1);
//	glBegin(GL_QUADS);
//	{
//		glTexCoord2f(0.0, 0.0);
//		glVertex3f(-1.0, -1.0, 0);
//
//		glTexCoord2f(1.0, 0.0);
//		glVertex3f(1.0f, -1.0f, 0);
//
//		glTexCoord2f(1.0, 1.0);
//		glVertex3f(1.0f, 1.0f, 0);
//
//		glTexCoord2f(0.0, 1.0);
//		glVertex3f(-1.0f, 1.0f, 0);
//	};
//	glEnd();
//	/** draw the needle **/
//	glBindTexture(GL_TEXTURE_2D, m_iNeedleTextureId);
//	glLoadIdentity();
//	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
//	glRotatef(m_dNeedleRotation + (360 - m_dGaugeMax), 0, 0, 1);
//	glScalef(m_vNeedleSize.x, m_vNeedleSize.y, 1);
//	glBegin(GL_QUADS);
//	{
//		glTexCoord2f(0.0, 0.0);
//		glVertex3f(-1.0, -1.0, 0);
//
//		glTexCoord2f(1.0, 0.0);
//		glVertex3f(1.0f, -1.0f, 0);
//
//		glTexCoord2f(1.0, 1.0);
//		glVertex3f(1.0f, 1.0f, 0);
//
//		glTexCoord2f(0.0, 1.0);
//		glVertex3f(-1.0f, 1.0f, 0);
//	};
//	glEnd();
//	/*glBegin(GL_QUADS);
//	{
//		glTexCoord2f(0.0, 0.0);
//		glVertex3f(m_vPosition.x - m_vHalfSize.x, m_vPosition.y - m_vHalfSize.y, 0);
//
//		glTexCoord2f(1.0, 0.0);
//		glVertex3f(m_vPosition.x + m_vHalfSize.x, m_vPosition.y - m_vHalfSize.y, 0);
//
//		glTexCoord2f(1.0, 1.0);
//		glVertex3f(m_vPosition.x + m_vHalfSize.x, m_vPosition.y + m_vHalfSize.y, 0);
//
//		glTexCoord2f(0.0, 1.0);
//		glVertex3f(m_vPosition.x - m_vHalfSize.x, m_vPosition.y + m_vHalfSize.y, 0);
//	};
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, m_iNeedleTextureId);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glRotatef(m_dNeedleRotation + (360 - m_dGaugeMax), 0, 0, 1);
//	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
//	glBegin(GL_QUADS);
//	{
//		glTexCoord2f(0.0, 0.0);
//		glVertex3f(m_vPosition.x - m_vNeedleSize.x, m_vPosition.y - m_vNeedleSize.y, 0);
//
//		glTexCoord2f(1.0, 0.0);
//		glVertex3f(m_vPosition.x + m_vNeedleSize.x, m_vPosition.y - m_vNeedleSize.y, 0);
//
//		glTexCoord2f(1.0, 1.0);
//		glVertex3f(m_vPosition.x + m_vNeedleSize.x, m_vPosition.y + m_vNeedleSize.y, 0);
//
//		glTexCoord2f(0.0, 1.0);
//		glVertex3f(m_vPosition.x - m_vNeedleSize.x, m_vPosition.y + m_vNeedleSize.y, 0);
//	};
//	glEnd();
//	glPopMatrix();*/
//	glDisable(GL_TEXTURE_2D);
};

void CircularGaugeWidget::onUpdate(double frameTime){
//	m_dNeedleRotation = (1 - ((m_dValue - m_dMin)/m_dRange)) * m_dGaugeRange;
};

