#include "afx.h"

Widget::Widget(){
	setDrawRectangle(0, 0, 100, 100);
}

Widget::~Widget(){
}

void Widget::setDrawRectangle(float _left, float _top, float _width, float _height){
	left = _left;
	top = _top;
	width = _width;
	height = _height;
}
void Widget::update(){
	getValuesFromSensors();
	onUpdate();
}
void Widget::getValuesFromSensors(){
	onGetValuesFromSensors();
}
void Widget::render(){
	onRender();
}

void Widget::onUpdate(){}
void Widget::onGetValuesFromSensors(){}
void Widget::onRender(){}
