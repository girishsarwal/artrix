/*
 * TimerWidget.cpp
 *
 *  Created on: May.16.2013
 *      Author: girish
 */
#include "TimerWidget.h"
#include "ViewManager.h"
#include "GameObjectFactory.h"
#include "Command.h"
namespace gtfx {
TimerWidget::TimerWidget()
	: mAccumulatedTime (0.0f)
	, mTime(0.0f)
	, mCommand (NULL){
	SetDefaultName("Timer");
}
TimerWidget::TimerWidget(tinyxml2::XMLNode* node)
	: mAccumulatedTime (0.0f)
	, mTime(0.0f)
	, mCommand (NULL){
	tinyxml2::XMLElement* elem = node->ToElement();
	if(NULL == elem) {
		printf("ERROR: TimerWidget:: Cannot parse XML");
		return;
	}
	SetName(elem->Attribute("name"));
	mTime = atoi(elem->Attribute("elapseTime"));
	GameObjectFactory::CreateCommand(elem->FirstChildElement("command")->FirstChild(), &mCommand);
}
TimerWidget::~TimerWidget() { }
void TimerWidget::OnInitialize() {

};

void TimerWidget::OnUpdate(double frameTime) {
	mAccumulatedTime+=frameTime;
	if(mAccumulatedTime >= mTime){
		mCommand->Execute();
		mAccumulatedTime = 0;
	};
};

bool TimerWidget::GetIsRunning() const {
	return mIsRunning;
}

void TimerWidget::SetIsRunning(bool isRunning) {
	mIsRunning = isRunning;
}

bool TimerWidget::ValidateAttributes() {
	return true;
};
void TimerWidget::Reset() {
	mAccumulatedTime = 0;
}
void TimerWidget::Start() {
	/** register with the clock **/
	mIsRunning = true;
}
void TimerWidget::Stop() {
	Pause();
	Reset();
	/** unregister with the clock **/
}
void TimerWidget::Pause() {
	mIsRunning = false;
}
}
