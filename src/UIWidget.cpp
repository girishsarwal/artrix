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
	setDrawRectangle(0, 0, 100, 100);
	m_vPosition.z = 0;
};

