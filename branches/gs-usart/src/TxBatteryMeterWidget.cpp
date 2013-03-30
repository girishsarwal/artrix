/*
 * TxBatteryMeterWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "afx.h"

TxBatteryMeterWidget::TxBatteryMeterWidget() {
	// TODO Auto-generated constructor stub

}

TxBatteryMeterWidget::~TxBatteryMeterWidget() {
	// TODO Auto-generated destructor stub
}

void TxBatteryMeterWidget::onRender(double frameTime){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutWireSphere(20, 10, 10);
}
