#include "View.h"
void View::update(double frameTime){
//	short index = -1;
//	onUpdate(frameTime);
//	int count = m_Widgets.Size();
//
//	while(++index < count)
//	{
//		if(NULL != m_Widgets.[index]){
//			m_Widgets[index]->Update(frameTime);
//		}
//	}
}
void View::render(double frameTime){
//	short index = -1;
//	int count = m_Widgets.Size();
//	onRender(frameTime);
//	while(++index < count){
//		if(NULL != m_Widgets[index]){
//			m_Widgets[index]->Draw(frameTime);
//		}
//	}
}

void View::addWidget(Widget* pWidget){
	//m_Widgets.add(pWidget);
}

void View::initialize(){
	//m_sName = std::string(as.get("name").getValue().c_str());
	onInitialize();
}

void View::onUpdate(double frameTime){

}
void View::onRender(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}
void View::onInitialize(){
	
}
View::View()
{
	//m_Widgets.clear();
}

View::~View(void)
{
}


