/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "ImageWidget.h"

ImageWidget::ImageWidget() {

};

ImageWidget::ImageWidget(tinyxml2::XMLNode* node) {

	tinyxml2::XMLElement* elem = node->ToElement();
	if(elem != NULL){
		SetName(elem->Attribute("name"));
		mSource = elem->FirstChildElement("src")->FirstChild()->Value();
	}
	printf("Source %s", mSource.c_str());
};

ImageWidget::~ImageWidget(){

}


void ImageWidget::OnInitialize(){
	Geometry::CreatePlaneGeometry(&mGeometry, 2, mSize);
	SetSource(mSource);
}


void ImageWidget::OnRender(double frameTime){
	TM->Use(mSource);
	SPM->Use("vc");
	mGeometry->Render();
	
}

void ImageWidget::OnAfterInitialize(){

			
	
}

bool ImageWidget::ValidateAttributes() {
	return true;
}

const std::string& ImageWidget::GetSource() const {
	return mSource;
};

void ImageWidget::SetSource(const std::string& source) {
	mSource = source;
};


