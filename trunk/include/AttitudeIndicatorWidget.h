#pragma once
#include "afx.h"
class AttitudeIndicatorWidget :
	public TelemetryWidget{
private:
	GLUquadricObj*	m_Gimbal;
		
public:
	float m_fPitch;
	float m_fRoll;
	float m_fYaw;
	std::string m_pGimbalTexture;
	std::string m_pPanelTexture;
	
	AttitudeIndicatorWidget();
	AttitudeIndicatorWidget(AttributeSet& as);
	~AttitudeIndicatorWidget();
	
	void onInitialize();
	void onCreate();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
};
