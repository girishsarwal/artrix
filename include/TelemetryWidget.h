/*
 * TelemetryWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once

#include "afx.h"

class TelemetryWidget: public UIWidget {
private:
	uint 	m_iTextureId;
protected:
	virtual void onGetValuesFromSensors();
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
public:
	std::string	m_pPath;
	TelemetryWidget();
	virtual ~TelemetryWidget();
	void getValuesFromSensors();
};


