/*
 * TelemetryWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once
#include "afx.h"
#include "UIWidget.h"
#include "SupportsTelemetry.h"

class TelemetryWidget
	: public gtfx::UIWidget
	, SupportsTelemetry{

protected:
	virtual void OnInitializeSensors();
	virtual void OnGetValuesFromSensors();
	virtual void OnInitialize();
	virtual void OnUpdate(double frameTime);

public:
	TelemetryWidget();
	TelemetryWidget(tinyxml2::XMLNode*);
	virtual ~TelemetryWidget();

	void InitializeSensors();
	void GetValuesFromSensors();
};


