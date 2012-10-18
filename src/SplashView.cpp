#include "afx.h"
SplashView::SplashView(){
	m_pSplashImage = NULL;

}

SplashView::~SplashView(){
}

void SplashView::onUpdate(){
	
}
void SplashView::onCreate(){
	TxBatteryMeterWidget *pWidget = new TxBatteryMeterWidget();
	addWidget(new TxBatteryMeterWidget());
}
void SplashView::onRender(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutWireSphere(10, 20, 20);
	printf("Drawing");
}

