#include "afx.h"

UIWidget::UIWidget(){
};

UIWidget::~UIWidget(){
};

void UIWidget::setDrawRectangle(float _left, float _top, float _width, float _height){
	m_vPosition.x = _left;
	m_vPosition.y = _top;
	m_vSize.x = _width;
	m_vSize.y = _height;
}


void UIWidget::onInitialize(){
	m_vPosition.x = atof(m_asAttributes.get("x").getValue().c_str());
	m_vPosition.y = atof(m_asAttributes.get("y").getValue().c_str());
	m_vPosition.z = atof(m_asAttributes.get("z").getValue().c_str());;
	
	m_vSize.x = atof(m_asAttributes.get("width").getValue().c_str());
	m_vSize.y = atof(m_asAttributes.get("height").getValue().c_str());
	m_fBackground = strtoll(m_asAttributes.get("background").getValue().c_str(), NULL, 16);

	printf("SETTING POS to %f, %f\n", m_vPosition.x, m_vPosition.y);
};

