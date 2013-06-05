/*
 * CircularGaugeWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		modified: girish
 */

#pragma once

#include "afx.h"
class CircularGaugeWidget: public UIWidget {
private:
	std::string m_sDialTexture;
	std::string m_sNeedleTexture;
	uint m_iDialTextureId;
	uint m_iNeedleTextureId;
	double m_dValue;
	double m_dMin;
	double m_dMax;
	double m_dRange;
	double m_dGaugeMin;
	double m_dGaugeMax;
	double m_dGaugeRange;
	
	double m_dNeedleRotation;

	Vector m_vNeedleSize;
protected:
	void onInitialize();
	void onRender(double frameTime);
	void onUpdate(double frameTime);
public:
	CircularGaugeWidget();
	CircularGaugeWidget(AttributeSet& attrs);
	virtual ~CircularGaugeWidget();
};


