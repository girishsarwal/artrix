#include "afx.h"
AttitudeIndicatorWidget::AttitudeIndicatorWidget(){
	m_fPitch = 0.0;
	m_fRoll = 0.0;
	m_fYaw = 0.0;
	m_pGimbalTexture = "att-ind-bg.png";
	m_pPanelTexture = "att-ind-panel.png";
};

AttitudeIndicatorWidget::AttitudeIndicatorWidget(AttributeSet& as){
	AttitudeIndicatorWidget();
	m_fPitch = 0.0;
	m_fRoll = 0.0;
	m_fYaw = 0.0;
	
	m_vPosition.x = atof(as.get("x").getValue().c_str());
	m_vPosition.y = atof(as.get("y").getValue().c_str());
	m_vPosition.z = atof(as.get("z").getValue().c_str());
	
	m_pGimbalTexture = "att-ind-bg.png";
	m_pPanelTexture = "att-ind-panel.png";
};

AttitudeIndicatorWidget::~AttitudeIndicatorWidget(){
};
float zPlane[] = {0.0f, 1.0f, 0.0f, 0.0f};
void AttitudeIndicatorWidget::onInitialize(){
	m_Gimbal = gluNewQuadric();
	gluQuadricTexture(m_Gimbal, GL_TRUE);
};

void AttitudeIndicatorWidget::onCreate(){
};
void AttitudeIndicatorWidget::onUpdate(double frameTime){
	m_fRoll += 0.5f;
	m_fPitch += 0.1f;
};
void AttitudeIndicatorWidget::onRender(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	{		
		glBindTexture(GL_TEXTURE_2D, TM->getTexture(m_pGimbalTexture));
		glTranslatef(m_vPosition.x, m_vPosition.y, 0);
		
		glRotatef(m_fPitch  - 90, 1, 0, 0);
		glRotatef(m_fRoll, 0, 1, 0);
		
		gluSphere(m_Gimbal, 20, 20, 20);
	};
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);
	glTranslatef(m_vPosition.x, m_vPosition.y, m_vPosition.z);
	glBindTexture(GL_TEXTURE_2D, TM->getTexture(m_pPanelTexture));
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0); 
		glVertex3f(-25, -25, 0);
		
		glTexCoord2f(1, 0); 
		glVertex3f(25, -25, 0);
		
		glTexCoord2f(1, 1); 
		glVertex3f(25, 25, 0);
		
		glTexCoord2f(0, 1); 
		glVertex3f(-25, 25, 0);
	};
	glEnd();
	glPopMatrix();
};

