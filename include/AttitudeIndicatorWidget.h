#pragma once
#include "afx.h"
class AttitudeIndicatorWidget :
	public Widget{
	private:
		float m_fRotation;
		GLUquadricObj*	m_Gimbal;
		
	public:
		AttitudeIndicatorWidget();
		AttitudeIndicatorWidget(AttributeSet& as);
		~AttitudeIndicatorWidget();
		void onInitialize();
		void onCreate();
		void onUpdate(double frameTime);
		void onRender(double frameTime);
};
