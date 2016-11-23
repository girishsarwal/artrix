#include "UIWidget.h"

UIWidget::UIWidget(){
	mIsVisible = true;

	mPosition.Set(0.0f, 0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0);
    mPivot.Set(0.5f, 0.5f, 0.5f);
    mGeometry = NULL;
};

UIWidget::UIWidget(tinyxml2::XMLNode* node){
	tinyxml2::XMLElement* elem = node->ToElement();
	if(NULL == elem) {
		printf("UIWidget - cannot parse xml");
		return;
	}
    mPosition = Vector3(node->FirstChildElement("position")->FirstChild());
    mSize = Vector3(node->FirstChildElement("size")->FirstChild());
    mIsVisible = true;
    mPivot = Vector3(node->FirstChildElement("anchor")->FirstChild());
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



