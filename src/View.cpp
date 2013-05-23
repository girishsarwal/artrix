#include "afx.h"
void View::update(double frameTime){
	short index = -1;
	onUpdate(frameTime);
	int count = m_Widgets.getCount();
	while(++index < count)
	{
		if(NULL != m_Widgets[index]){
			m_Widgets[index]->update(frameTime);
		}
	}
}
void View::render(double frameTime){
	short index = -1;
	int count = m_Widgets.getCount();
	onRender(frameTime);
	while(++index < count){
		if(NULL != m_Widgets[index]){
			m_Widgets[index]->render(frameTime);
		}
	}
}

void View::addWidget(Widget* pWidget){
	m_Widgets.add(pWidget);
}

void View::initialize(AttributeSet& as){
	m_sName = std::string(as.get("name").getValue().c_str());
	onInitialize(as);
}

void View::onUpdate(double frameTime){

}
void View::onRender(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}
void View::onInitialize(AttributeSet& as){
	
}
View::View()
{
	m_Widgets.clear();
}

View::~View(void)
{
}


