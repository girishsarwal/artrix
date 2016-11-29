#include "UIWidget.h"

UIWidget::UIWidget()
	:Widget()
	,mTransformComponent(new gtfx::TransformComponent())
	,mRenderComponent(new gtfx::RenderComponent())
{


};

UIWidget::UIWidget(tinyxml2::XMLNode* node)
	:Widget(node)
	,mTransformComponent(new gtfx::TransformComponent())
	,mRenderComponent(new gtfx::RenderComponent()) {
	tinyxml2::XMLElement* elem = node->ToElement();
	if(NULL == elem) {
		printf("UIWidget - cannot parse xml");
		return;
	}
	mTransformComponent->SetPosition(vec3fromXmlNode(node->FirstChildElement("position")->FirstChild()));
	mTransformComponent->SetSize(vec3fromXmlNode(node->FirstChildElement("size")->FirstChild()));
	mTransformComponent->SetPivot(vec3fromXmlNode(node->FirstChildElement("anchor")->FirstChild()));
};

UIWidget::~UIWidget(){
};

void UIWidget::OnInitialize(){
	mComponents.push_back(mTransformComponent);
	mComponents.push_back(mRenderComponent);
	Widget::OnInitialize();
}
void UIWidget::OnUpdate(double gameTime){
	mRenderComponent->Render(gameTime);		//TODO: This will get replaced by EnqueueForRender()
	Widget::OnUpdate(gameTime);
}



