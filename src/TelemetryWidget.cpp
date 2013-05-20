#include "afx.h"

TelemetryWidget::TelemetryWidget(){
	Widget::Widget();
};

TelemetryWidget::~TelemetryWidget(){
}

void TelemetryWidget::onGetValuesFromSensors(){
};

void TelemetryWidget::getValuesFromSensors(){
	onGetValuesFromSensors();
};

