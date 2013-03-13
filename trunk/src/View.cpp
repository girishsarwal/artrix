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
	onRender(frameTime);
	while(++index < count){
		if(NULL != m_Widgets.getAtIndex(index)){
			m_Widgets.getAtIndex(index)->render(frameTime);
		}
	}
}

void View::addWidget(Widget* pWidget){
	printf("adding widget at adress %x\n", pWidget);
	m_Widgets.add(pWidget);
	printf("New Size is %d\n", m_Widgets.getCount());
}

void View::create(){
	onCreate();
}

void View::onUpdate(double frameTime){

}
void View::onRender(double frameTime){
	printf("Rendering View\n");
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


