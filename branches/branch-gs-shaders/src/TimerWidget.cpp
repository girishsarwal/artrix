/*
 * TimerWidget.cpp
 *
 *  Created on: May.16.2013
 *      Author: girish
 */

#include "afx.h"

TimerWidget::TimerWidget() {
	// TODO Auto-generated constructor stub

}

TimerWidget::~TimerWidget() {
	// TODO Auto-generated destructor stub
}


static float fElapsedTime = 0.0f;

void TimerWidget::initialize(AttributeSet& as){
	m_asAttributes = as;
	m_fTime = atof(m_asAttributes.get("timeout").getValue().c_str());
	m_sAction = m_asAttributes.get("action").getValue().c_str();
	m_sTargetView = m_asAttributes.get("targetView").getValue().c_str();
};

void TimerWidget::update(double frameTime){
	fElapsedTime+=frameTime;
	if(fElapsedTime >=m_fTime){
		VM->changeView(VM->getView(m_sTargetView));
		fElapsedTime = 0;
	};
};
void TimerWidget::render(double frameTime){
};
