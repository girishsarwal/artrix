#include "UIWidget.h"

UIWidget::UIWidget(){
	mIsVisible = true;

	mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    mSize = glm::vec3(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0);
    mPivot = glm::vec3(0.5f, 0.5f, 0.5f);
    mGeometry = NULL;
};

UIWidget::UIWidget(tinyxml2::XMLNode* node)
	: Widget(node),
	  Renderable() {
	tinyxml2::XMLElement* elem = node->ToElement();
	if(NULL == elem) {
		printf("UIWidget - cannot parse xml");
		return;
	}
	mPosition = vec3fromXmlNode(node->FirstChildElement("position")->FirstChild());
	mSize = vec3fromXmlNode(node->FirstChildElement("size")->FirstChild());
	mPivot = vec3fromXmlNode(node->FirstChildElement("anchor")->FirstChild());
    mIsVisible = true;
    mGeometry = NULL;
};

UIWidget::~UIWidget(){
};

void UIWidget::OnInitialize(){
	 SetPosition(mPosition);     /** I know this sounds stupid to do but C++ makes objects like an onion, inside out and we need to call some virt func during creation **/
	 SetSize(mSize);
	 SetPivot(mPivot);
	 SetIsVisible(mIsVisible);
}
void UIWidget::OnUpdate(double gameTime){
	Render(gameTime);		//TODO: This will get replaced by EnqueueForRender()
}



