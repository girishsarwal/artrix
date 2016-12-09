/*
 * TimerWidget.h
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#pragma once
#include "GameObject.h"
#include "afx.h"
#include "ViewManager.h"
#include "Command.h"

class TimerWidget
	: public gtfx::GameObject {
private:
	float mAccumulatedTime;
protected:

	uint mTime;
	gtfx::Command* mCommand;
	/*** lifecycle **/
	void OnInitialize();
	void OnUpdate(double frameTime);

public:
	TimerWidget();
	TimerWidget(tinyxml2::XMLNode*);
	virtual ~TimerWidget();
	bool ValidateAttributes();

};


