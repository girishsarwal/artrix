#include "afx.h"
AttitudeIndicatorWidget::AttitudeIndicatorWidget(){
	m_fRotation = 0;
};

AttitudeIndicatorWidget::AttitudeIndicatorWidget(AttributeSet& as){
	AttitudeIndicatorWidget();
	m_vPosition.x = atof(as.get("x").getValue().c_str());
	m_vPosition.y = atof(as.get("y").getValue().c_str());
};

AttitudeIndicatorWidget::~AttitudeIndicatorWidget(){
};
float zPlane[] = {0.0f, 1.0f, 0.0f, 0.0f};
void AttitudeIndicatorWidget::onInitialize(){
	m_iTextureId = TM->getTexture(std::string("att-ind-bg.png"));
	printf("Selected Texture %d", m_iTextureId);
};

void AttitudeIndicatorWidget::onCreate(){
};
void AttitudeIndicatorWidget::onUpdate(double frameTime){
	m_fRotation += 2.0f;
};
void AttitudeIndicatorWidget::onRender(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glRotatef(m_fRotation, 0.0, 1.0, 0.0);
	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
	
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glDepthMask(GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, m_iTextureId);
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	
	glTexGenfv(GL_S, GL_OBJECT_PLANE, zPlane);
    glTexGenfv(GL_T, GL_OBJECT_PLANE, zPlane);
    
    
	glutSolidSphere(20, 20, 20);
	
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	
	glPopMatrix();
};

