/*
* CircularGaugeWidget.cpp
*
*  Created on: Aug 29, 2012
*      Author: manmohan
* 		Modified: girish
*/

#include "CircularGaugeWidget.h"

CircularGaugeWidget::CircularGaugeWidget() {

};
CircularGaugeWidget::CircularGaugeWidget(tinyxml2::XMLNode*) {

};
CircularGaugeWidget::~CircularGaugeWidget() {

};

void CircularGaugeWidget::OnInitialize() {

};
void CircularGaugeWidget::OnRender(double) {

};
void CircularGaugeWidget::OnInitializeSensors() {

};
void CircularGaugeWidget::OnGetValuesFromSensors() {

};
bool CircularGaugeWidget::ValidateAttributes() {
	return true;
};



const std::string& CircularGaugeWidget::GetDialTexture() const {
	return mDialTexture;
};
void CircularGaugeWidget::SetDialTexture(const std::string& dialTexture) {
	mDialTexture = dialTexture;
};
const std::string& CircularGaugeWidget::GetNeedleTexture() const {
	return mNeedleTexture;
};
void CircularGaugeWidget::SetNeedleTexture(const std::string& needleTexture) {
	mNeedleTexture = needleTexture;
};
double CircularGaugeWidget::GetValue() {
	return mValue;
};
void CircularGaugeWidget::SetValue(double value) {
	mValue = value;
};

const Vector3& CircularGaugeWidget::GetMinimus() const {
	return mMinimus;
};
void CircularGaugeWidget::SetMinimums(const Vector3& minimus) {
	mMinimus = minimus;
};
const Vector3& CircularGaugeWidget::GetMaximus() const {
	return mMaximus;
};
void CircularGaugeWidget::SetMaximus(const Vector3& maximus) {
	mMaximus = maximus;
};
double CircularGaugeWidget::GetNeedleRotation() {
	return mNeedleRotation;
};
void CircularGaugeWidget::SetNeedleRotation(double needleRotation) {
	mNeedleRotation = needleRotation;
};
const Vector3& CircularGaugeWidget::GetNeedleSize() const {
	return mNeedleSize;
};
void CircularGaugeWidget::SetNeedleSize(const Vector3& needleSize) {
	mNeedleSize = needleSize;
};
void CircularGaugeWidget::CalculateRanges() {

};
