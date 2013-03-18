#include "afx.h"

Widget::Widget(){
	setDrawRectangle(0, 0, 100, 100);
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
	getValuesFromSensors();
	onUpdate(frameTime);
}
void Widget::getValuesFromSensors(){
	onGetValuesFromSensors();
}
void Widget::render(double frameTime){
	if(!m_bInitialized) initialize();
	printf("Rendering Widget\n");
	onRender(frameTime);
}
void Widget::initialize(){
	printf("Initializing Widget");
	onInitialize();
	m_bInitialized = true;
}

void Widget::onUpdate(double frameTime){}
void Widget::onGetValuesFromSensors(){}
void Widget::onRender(double frameTime){
	
	}
void Widget::onInitialize(){}
