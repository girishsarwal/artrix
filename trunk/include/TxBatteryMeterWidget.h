/*
 * TxBatteryMeterWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once
#include "artrix-includes.h"


class TxBatteryMeterWidget: public Widget {
private:
	long m_lLowBatteryThreshold;
	long m_lVeryLowBatteryThreshold;
	bool m_bShowInPercent;	/*toggles on click/touch/whatever/auto */
public:
	/**
	 * Anything above lowBatteryThreshold = Green Battery
	 * Anything under lowBatteryThreshold = Yellow Battery
	 * Anything under veryLowBatteryThreshold = Red Battery + Alarm
	 */
	void setThresholds(long lowBatteryThreshold, long veryLowBatteryThreshold);

	/**
	 * set range of battery, used to calculate percent option
	 */
	void setBatteryRange(long min, long max);
	void onRender();

	TxBatteryMeterWidget();
	virtual ~TxBatteryMeterWidget();
};


