#ifndef SPLASHVIEW_H
#define SPLASHVIEW_H
#include "afx.h"
#include "View.h"
#include "ImageWidget.h"
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
#endif
