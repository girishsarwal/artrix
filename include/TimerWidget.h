/*
 * TimerWidget.h
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H
#include "afx.h"
#include "GameObject.h"
namespace gtfx {
class Command;
class TimerWidget
	: public GameObject {
private:
	float mAccumulatedTime;
protected:

	uint mTime;
	Command* mCommand;
	/*** lifecycle **/
	void OnInitialize();
	void OnUpdate(double frameTime);

public:
	TimerWidget();
	TimerWidget(tinyxml2::XMLNode*);
	virtual ~TimerWidget();
	bool ValidateAttributes();
};
}
#endif
