#pragma once
#include "artrix-includes.h"
class SplashView
	: public View
{
private:
		ImageWidget*	m_pSplashImage;
public:
	SplashView();
	virtual ~SplashView();
	void onRender();
	void onUpdate();
	void onCreate();
};

