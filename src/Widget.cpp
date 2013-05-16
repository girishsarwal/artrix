#include "afx.h"

Widget::Widget(){
	setDrawRectangle(0, 0, 100, 100);
	m_vPosition.z = 0;
}

Widget::~Widget(){
}

void Widget::setDrawRectangle(float _left, float _top, float _width, float _height){
	m_vPosition.x = _left;
	m_vPosition.y = _top;
	m_vSize.x = _width;
	m_vSize.y = _height;
}
void Widget::update(double frameTime){
	onUpdate(frameTime);
}

void Widget::render(double frameTime){
	onRender(frameTime);
}
void Widget::initialize(AttributeSet& as){
	m_asAttributes = as;

	onInitialize();
	m_bInitialized = true;
}

void Widget::onInitialize(){}
void Widget::onUpdate(double frameTime){}
void Widget::onRender(double frameTime){}

