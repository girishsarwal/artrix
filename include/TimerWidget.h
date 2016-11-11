/*
 * TimerWidget.h
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#pragma once
#include "TimerWidget.h"


class TimerWidget
	: public Widget {
private:
	float m_fTime;
	std::string m_sTargetView;
	std::string m_sAction;
	
public:
	TimerWidget();
	TimerWidget(AttributeSet& as);
	virtual ~TimerWidget();
	void initialize(AttributeSet& as);
	void update(double frameTime);
	void render(double frameTime);
};


