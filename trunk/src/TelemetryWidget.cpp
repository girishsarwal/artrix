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
void TelemetryWidget::onInitialize(){
	UIWidget::onInitialize();
};
void TelemetryWidget::onUpdate(double frameTime){
	UIWidget::onUpdate(frameTime);
};
void TelemetryWidget::onRender(double frameTime){
	UIWidget::onRender(frameTime);
};

