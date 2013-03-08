#include "afx.h"
void View::update(double frameTime){
	short index = -1;
	onUpdate(frameTime);
	while(++index < MAX_WIDGETS)
	{
		if(pWidgets[index]){
			pWidgets[index]->update(frameTime);
		}
	}
}
void View::render(double frameTime){
	short index = -1;
	onRender(frameTime);
	while(++index < MAX_WIDGETS){
		if(pWidgets[index]){
			pWidgets[index]->render(frameTime);
		}
	}
}
void View::create(){
	onCreate();
}
void View::addWidget(Widget* _pWidget){
	if(m_nWidgetCount >=MAX_WIDGETS)
	{
		/** alert no more widgets can be added on this screen. Please remove some widgets **/
		return;
	}
	m_nWidgetCount++;
}
void View::removeWidget(Widget* _pWidget){
	if(m_nWidgetCount <=0)
	{
		/** no widgets to remove **/
	}
	m_nWidgetCount--;
}

void View::onUpdate(double frameTime){

}
void View::onRender(double frameTime){

}

View::View(void)
{
	/** Zero out the memory on the arrays **/
	memset(pWidgets, NULL, MAX_WIDGETS * 4);
}

View::~View(void)
{
}


