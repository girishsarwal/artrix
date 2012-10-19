#include "artrix-includes.h"
void View::update(){
	short index = -1;
	onUpdate();
	while(++index < MAX_WIDGETS)
	{
		if(pWidgets[index]){
			pWidgets[index]->update();
		}
	}
}
void View::render(){
	short index = -1;
	onRender();
	while(++index < MAX_WIDGETS){
		if(pWidgets[index]){
			pWidgets[index]->render();
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

void View::onUpdate(){

}
void View::onRender(){

}

View::View(void)
{
	/** Zero out the memory on the arrays **/
	memset(pWidgets, NULL, MAX_WIDGETS * 4);
}

View::~View(void)
{
}


