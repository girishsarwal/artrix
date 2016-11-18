/*
 * TimerWidget.h
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#pragma once
#include "afx.h"
#include "Widget.h"
#include "ViewManager.h"

class TimerWidget
	: public Widget {
private:
	float mAccumulatedTime;
protected:

	float mTime;
	std::string mTargetView;
	std::string mAction;
	std::string mParam1;
	std::string mParam2;

	/** property hooks **/
	virtual void OnSetAction();
	virtual void OnSetParam1();
	virtual void OnSetParam2();

	/*** lifecycle **/
	void OnInitialize();
	void OnUpdate(double frameTime);

public:
	TimerWidget();
	TimerWidget(tinyxml2::XMLNode*);
	virtual ~TimerWidget();

	const std::string& GetAction() const;
	void SetAction(const std::string&);
	const std::string GetParam1() const;
	void SetParam1(const std::string&);
	const std::string GetParam2() const;
	void SetParam2(const std::string&);

	bool ValidateAttributes();

};


