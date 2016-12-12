#include "UIWidget.h"
#include "Program.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
namespace gtfx {
UIWidget::UIWidget()
	:GameObject()
	,mTransformComponent(new gtfx::TransformComponent())
	,mRenderComponent(new gtfx::RenderComponent())
{


};

UIWidget::UIWidget(tinyxml2::XMLNode* node)
	:GameObject(node)
	, mShadingProgram (NULL)
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
	GameObject::OnInitialize();
}
void UIWidget::OnUpdate(double gameTime){

//	glm::mat4 Projection = glm::perspective(glm::radians(60.0f), (float) 4/ (float)3, 0.1f, 100.0f);
//
//	// Or, for an ortho camera :
//	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
//
//	// Camera matrix
//	glm::mat4 View = glm::lookAt(
//	    glm::vec3(0,0,5), // Camera is at (4,3,3), in World Space
//	    glm::vec3(0,0,0), // and looks at the origin
//	    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
//	    );
//
//	// Model matrix : an identity matrix (model will be at the origin)
//	glm::mat4 Model = glm::mat4(1.0f);
//	// Our ModelViewProjection : multiplication of our 3 matrices
//	glm::mat4 mvp = Projection * View * mTransformComponent->GetWorld(); //

	mRenderComponent->GetProgram()->SetUniformMatrix4fv("in_mvp", mTransformComponent->GetWorld());
	mRenderComponent->Render(gameTime);		//TODO: This will get replaced by EnqueueForRender()
	GameObject::OnUpdate(gameTime);
}

}
