/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "ImageWidget.h"

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
	TM->Use(mSource);

	Program* program = SPM->Get("sprite");
	program->SetUniform1i("texture", TM->Get(mSource)->GetTextureId());
	program->Use();
	gtfx::Geometry::CreatePlaneGeometry(mRenderComponent->GetGeometry(), 2, mTransformComponent->GetSize());
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


