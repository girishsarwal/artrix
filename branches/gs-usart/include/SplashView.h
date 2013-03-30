#pragma once
#include "afx.h"
class SplashView
	: public View
{
private:
		ImageWidget*	m_pSplashImage;
public:
	SplashView();
	virtual ~SplashView();
	void onRender(double frameTime);
	void onUpdate(double frameTime);
	void onCreate();
};

