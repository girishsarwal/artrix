#include "TelemetryWidget.h"

TelemetryWidget::TelemetryWidget() {

};

TelemetryWidget::TelemetryWidget(tinyxml2::XMLNode*) {

};

TelemetryWidget::~TelemetryWidget() {

};


void TelemetryWidget::OnInitializeSensors() {

};
void TelemetryWidget::OnGetValuesFromSensors() {
	OnGetValuesFromSensors();
};

void TelemetryWidget::OnInitialize() {
	InitializeSensors();
};

void TelemetryWidget::OnUpdate(double frameTime) {
	GetValuesFromSensors();
};

void TelemetryWidget::InitializeSensors() {
	OnInitializeSensors();
};

void TelemetryWidget::GetValuesFromSensors() {

};
