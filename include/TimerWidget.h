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
	float m_fTime;
	std::string m_sTargetView;
	std::string m_sAction;
	
public:
	TimerWidget();
	TimerWidget(tinyxml2::XMLNode*);
	virtual ~TimerWidget();
	void initialize();
	void update(double frameTime);
	void render(double frameTime);
};


