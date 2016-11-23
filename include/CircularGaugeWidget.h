/*
 * CircularGaugeWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		modified: girish
 */

#ifndef CIRCULARGAUGEWIDGET_H
#define CIRCULARGAUGEWIDGET_H
#include "afx.h"
#include "TelemetryWidget.h"
#include "Vector3.h"
class CircularGaugeWidget:
	public TelemetryWidget {
private:
	std::string mDialTexture;
	std::string mNeedleTexture;

	double mValue;
	
	Vector3 mMinimus;
	Vector3 mMaximus;
	Vector3 mRanges;

	double mNeedleRotation;
	Vector3 mNeedleSize;

protected:
	void OnInitialize();
	void OnRender(double);
	void OnInitializeSensors();
	void OnGetValuesFromSensors();
	bool ValidateAttributes();

public:
	CircularGaugeWidget();
	CircularGaugeWidget(tinyxml2::XMLNode*);
	virtual ~CircularGaugeWidget();

	const std::string& GetDialTexture() const;
	void SetDialTexture(const std::string&);
	const std::string& GetNeedleTexture() const;
	void SetNeedleTexture(const std::string&);
	double GetValue();
	void SetValue(double value);

	const Vector3& GetMinimus() const;
	void SetMinimums(const Vector3&);
	const Vector3& GetMaximus() const;
	void SetMaximus(const Vector3&);
	double GetNeedleRotation();
	void SetNeedleRotation(double);
	const Vector3& GetNeedleSize() const;
	void SetNeedleSize(const Vector3&);
	void CalculateRanges();

};
#endif
