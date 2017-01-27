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
	uint mAccumulatedTime;
protected:
	bool mIsRunning;
	uint mTime;
	Command* mCommand;
	/*** lifecycle **/
	void OnInitialize();
	void OnUpdate(double frameTime);

public:
	TimerWidget();
	TimerWidget(tinyxml2::XMLNode*);

	void Reset();			/** reset the timer **/
	void Start();			/** register with the clock **/
	void Stop();			/** unregister with the clock **/
	void Pause();			/** just pause **/

	virtual ~TimerWidget();
	bool ValidateAttributes();
	bool GetIsRunning() const;
	void SetIsRunning(bool isRunning);
};
}
#endif
