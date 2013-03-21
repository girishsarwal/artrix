#pragma once
#include "afx.h"
class AttitudeIndicatorWidget :
	public Widget{
	private:
		float m_fPitch;
		float m_fRoll;
		float m_fYaw;
		
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
