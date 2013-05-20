/*
 * TimerWidget.h
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#pragma once
#include "afx.h"


class TimerWidget: public Widget {
private:
	float m_fTime;
	std::string m_sTargetView;
	std::string m_sAction;
	
public:
	void onUpdate(double frameTime);
	TimerWidget();
	TimerWidget(AttributeSet& as);
	virtual ~TimerWidget();
	void onInitialize();
	void onCreate();
	void onUpdate(double frameTime);
};


