#include "AttitudeIndicatorWidget.h"

AttitudeIndicatorWidget::AttitudeIndicatorWidget() {

};
AttitudeIndicatorWidget::AttitudeIndicatorWidget(tinyxml2::XMLNode*) {

};
AttitudeIndicatorWidget::~AttitudeIndicatorWidget() {

};

void AttitudeIndicatorWidget::OnInitialize() {
	SetGimbalTexture(mGimbalTexture);
	SetPanelTexture(mPanelTexture);
	SetOrientation(mOrientation);
};

void AttitudeIndicatorWidget::OnRender(double gameTime) {

};

void AttitudeIndicatorWidget::OnInitializeSensors() {

};

void AttitudeIndicatorWidget::OnGetValuesFromSensors(){

};



const std::string& AttitudeIndicatorWidget::GetGimbalTexture() const {
	return mGimbalTexture;
}
void AttitudeIndicatorWidget::SetGimbalTexture(const std::string& gimbalTexture) {
	mGimbalTexture = gimbalTexture;
}
const std::string& AttitudeIndicatorWidget::GetPanelTexture() const {
	return mPanelTexture;
}
void AttitudeIndicatorWidget::SetPanelTexture(const std::string& panelTexture) {
	mPanelTexture = panelTexture;
}
const Vector3& AttitudeIndicatorWidget::GetOrientation() const {
	return mOrientation;
}
void AttitudeIndicatorWidget::SetOrientation(const Vector3& orientation) {
	mOrientation = orientation;
}

bool AttitudeIndicatorWidget::ValidateAttributes() {
	return true;
}
