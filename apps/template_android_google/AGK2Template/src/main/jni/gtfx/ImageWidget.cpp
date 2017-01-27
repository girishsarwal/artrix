/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "ImageWidget.h"
#include "Texture.h"
#include "TextureManager.h"
#include "ShadingProgramManager.h"
#include "Geometry.h"
namespace gtfx {
ImageWidget::ImageWidget()
	:UIWidget() {

};

ImageWidget::ImageWidget(tinyxml2::XMLNode* node)
	: UIWidget(node) {

	tinyxml2::XMLElement* elem = node->ToElement();
	if(elem != NULL){
		SetName(elem->Attribute("name"));
		mSource = elem->FirstChildElement("src")->FirstChild()->Value();
	}
};

ImageWidget::~ImageWidget(){

}

void ImageWidget::OnBeforeInitialize() {


	mRenderComponent->SetProgram(ShadingProgramManager::GetInstance()->Get("sprite"));
	Texture *texture = TextureManager::GetInstance()->Get(mSource);
	mRenderComponent->SetTexture(texture);

	//gtfx::Geometry::CreatePlaneGeometry(mRenderComponent->GetGeometry(), 2, mTransformComponent->GetSize());
	Geometry::CreatePlaneGeometry(mRenderComponent->GetGeometry(), mRenderComponent->GetVertexDefinition(), mTransformComponent->GetSize(), glm::vec3(0, 0, 0));

	UIWidget::OnBeforeInitialize();
}
void ImageWidget::OnInitialize(){
	SetSource(mSource);
	UIWidget::OnInitialize();
}


void ImageWidget::OnAfterInitialize(){
	UIWidget::OnAfterInitialize();
}

bool ImageWidget::ValidateAttributes() {
	UIWidget::ValidateAttributes();
	return true;
}

const std::string& ImageWidget::GetSource() const {
	return mSource;
};

void ImageWidget::SetSource(const std::string& source) {
	mSource = source;
};
}
