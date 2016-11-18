#include "UIWidget.h"

UIWidget::UIWidget(){
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_pShadingProgram = NULL;
	m_iSizeIndices = 0;
	m_iSizeVertex = 0;
	m_iSizeVertices = 0;
	mIsVisible = true;
	m_iNumTriangles = 0;

	mPosition.Set(0.0f, 0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0);
    mPivot.Set(0.5f, 0.5f, 0.5f);

};

UIWidget::UIWidget(tinyxml2::XMLNode* node){
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_pShadingProgram = NULL;
	m_iSizeIndices = 0;
	m_iSizeVertex = 0;
	m_iSizeVertices = 0;
	mIsVisible = true;
	m_iNumTriangles = 0;

	tinyxml2::XMLElement* elem = node->ToElement();
	if(NULL == elem) {
		printf("UIWidget - cannot parse xml");
		return;
	}
    mPosition = Vector3(node->FirstChildElement("position")->FirstChild());
    mSize = Vector3(node->FirstChildElement("size")->FirstChild());
    mIsVisible = true;
    mPivot = Vector3(node->FirstChildElement("anchor")->FirstChild());

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
	Render(gameTime);
}



