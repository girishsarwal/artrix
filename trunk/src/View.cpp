#include "afx.h"
void View::update(double frameTime){
	short index = -1;
	onUpdate(frameTime);
	int count = m_Widgets.getCount();
	while(++index < count)
	{
		if(NULL != m_Widgets.getAtIndex(index)){
			m_Widgets.getAtIndex(index)->update(frameTime);
		}
	}
}
void View::render(double frameTime){
	short index = -1;
	int count = m_Widgets.getCount();
	printf("widgest count is %d", count);
	onRender(frameTime);
	while(++index < count){
		if(NULL != m_Widgets.getAtIndex(index)){
			m_Widgets.getAtIndex(index)->render(frameTime);
		}
	}
}

void View::addWidget(Widget* pWidget){
	printf("adding widget");
	m_Widgets.add(pWidget);
}

void View::create(){
	onCreate();
}

void View::onUpdate(double frameTime){

}
void View::onRender(double frameTime){
	
}
void View::onCreate(){
	
}

View::View(void)
{
	m_Widgets.clear();
}

View::~View(void)
{
}


