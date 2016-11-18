/*
 * TimerWidget.cpp
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#include "TimerWidget.h"


TimerWidget::TimerWidget() {
	mAccumulatedTime = 0.0f;
	mTime = 0.0f;
	SetDefaultName("Timer");
}
TimerWidget::TimerWidget(tinyxml2::XMLNode*) {
	mAccumulatedTime = 0.0f;
	mTime = 0.0f;
	SetDefaultName("Timer");
}
TimerWidget::~TimerWidget() { }


const std::string& TimerWidget::GetAction() const {
	return mAction;
};

void TimerWidget::SetAction(const std::string& action) {
	mAction = action;
};

const std::string TimerWidget::GetParam1() const {
	return mParam1;
};

void TimerWidget::SetParam1(const std::string& param1) {
	mParam1 = param1;
};

const std::string TimerWidget::GetParam2() const {
	return mParam2;
};

void TimerWidget::SetParam2(const std::string& param2) {
	mParam2 = param2;
};

void TimerWidget::OnInitialize() {
	SetAction(mAction);
	SetParam1(mParam1);
	SetParam2(mParam2);
};

void TimerWidget::OnUpdate(double frameTime) {
	mAccumulatedTime+=frameTime;
	if(mAccumulatedTime >= mTime){
		//VM->ChangeView(VM->Get(m_sTargetView));		TODO: Action manager
		mAccumulatedTime = 0;
	};
};

void TimerWidget::OnSetAction() {

};

void TimerWidget::OnSetParam1() {

};

void TimerWidget::OnSetParam2() {

};

bool ValidateAttributes() {
	return true;
};
