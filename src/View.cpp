#include "View.h"

void View::Update(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	onUpdate(frameTime);
	std::vector<Widget*>::const_iterator it = mWidgets.begin();
	while(it != mWidgets.end()){
		(*it)->Update(frameTime);
		it++;
	}
}

void View::AddWidget(Widget* widget){
	mWidgets.push_back(widget);
}

void View::initialize(){
	onInitialize();
}

void View::onUpdate(double frameTime) {

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


