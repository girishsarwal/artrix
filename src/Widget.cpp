#include "afx.h"

Widget::Widget(){

};

Widget::~Widget(){
};

void Widget::update(double frameTime){
	onUpdate(frameTime);
};
void Widget::render(double frameTime){
	onRender(frameTime);
};
void Widget::initialize(AttributeSet& as){
	m_asAttributes = as;
	onInitialize();
	m_bInitialized = true;
};

void Widget::onInitialize(){
};
void Widget::onUpdate(double frameTime){
};
void Widget::onRender(double frameTime){
};

