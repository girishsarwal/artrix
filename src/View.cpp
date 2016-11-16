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

void View::AddWidget(Widget* pWidget){

}

void View::initialize(){
	onInitialize();
}

void View::onUpdate(double frameTime) {

}
void View::onRender(double frameTime) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}
void View::onInitialize() {
	
}
View::View() {
	SetDefaultName("View");
}

View::View(tinyxml2::XMLNode* node) {
	tinyxml2::XMLElement* elem = node->ToElement();
	if(elem != NULL){
		SetName(elem->Attribute("name"));
	}
}

View::~View(void)
{
}


