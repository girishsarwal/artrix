#pragma once
#include "afx.h"
class AttitudeIndicatorWidget :
	public Widget{
	private:
		float m_fRotation;
		uint m_iTextureId;
	public:
		AttitudeIndicatorWidget();
		AttitudeIndicatorWidget(AttributeSet& as);
		~AttitudeIndicatorWidget();
		void onInitialize();
		void onCreate();
		void onUpdate(double frameTime);
		void onRender(double frameTime);
};
