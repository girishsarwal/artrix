#include "TelemetryWidget.h"

TelemetryWidget::TelemetryWidget(){
};

TelemetryWidget::~TelemetryWidget(){
}

void TelemetryWidget::onGetValuesFromSensors(){
};

void TelemetryWidget::getValuesFromSensors(){
	onGetValuesFromSensors();
};
void TelemetryWidget::onInitialize(){
		getValuesFromSensors();
};
void TelemetryWidget::onUpdate(double frameTime){

};
void TelemetryWidget::onRender(double frameTime){

};

