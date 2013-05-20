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
	std::string	m_pPath;
	unsigned long long m_fBackground;
	uint 	m_iTextureId;
protected:
	virtual void onGetValuesFromSensors();
	
public:
	TelemetryWidget();
	virtual ~TelemetryWidget();
	void getValuesFromSensors();
};


