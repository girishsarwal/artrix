#include "afx.h"

UIWidget::UIWidget(){
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_pShadingProgram = NULL;
};

UIWidget::~UIWidget(){
};

void UIWidget::setDrawRectangle(float _left, float _top, float _width, float _height){
	m_vPosition.x = _left;
	m_vPosition.y = _top;
	m_vSize.x = _width;
	m_vSize.y = _height;
}


void UIWidget::initialize(AttributeSet& as){
	m_asAttributes = as;
	beforeInitialize();
	onInitialize();
	afterInitialize();
};

void UIWidget::beforeInitialize(){
	m_vPosition.x = atof(m_asAttributes.get("x").getValue().c_str());
	m_vPosition.y = atof(m_asAttributes.get("y").getValue().c_str());
	m_vPosition.z = atof(m_asAttributes.get("z").getValue().c_str());;
	
	m_vSize.x = atof(m_asAttributes.get("width").getValue().c_str());
	m_vSize.y = atof(m_asAttributes.get("height").getValue().c_str());
	m_vHalfSize = m_vSize;
	m_vHalfSize.scale(0.5);
	m_fBackground = strtoll(m_asAttributes.get("background").getValue().c_str(), NULL, 16);
};

void UIWidget::afterInitialize(){
	m_bInitialized = true;
};



void UIWidget::render(double frameTime){
	beforeRender(frameTime);
	onRender(frameTime);
	afterRender(frameTime);
}

void UIWidget::beforeRender(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	
	glLoadIdentity();
	glTranslatef(m_vPosition.x, m_vPosition.y, 0);
	glScalef(m_vSize.x, m_vSize.y, 1);
};

void UIWidget::afterRender(double frameTime){
	glPopAttrib();
	glPopMatrix();
};

void UIWidget::update(double frameTime){
	beforeUpdate(frameTime);
	onUpdate(frameTime);
	afterUpdate(frameTime);
};

void UIWidget::beforeUpdate(double frameTime){
};

void UIWidget::afterUpdate(double frameTime){
};