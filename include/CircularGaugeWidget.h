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
class CircularGaugeWidget:
	public TelemetryWidget {
private:
	std::string mDialTexture;
	std::string mNeedleTexture;

	double mValue;
	
	glm::vec3 mMinimus;
	glm::vec3 mMaximus;
	glm::vec3 mRanges;

	double mNeedleRotation;
	glm::vec3 mNeedleSize;

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

	const glm::vec3& GetMinimus() const;
	void SetMinimums(const glm::vec3&);
	const glm::vec3& GetMaximus() const;
	void SetMaximus(const glm::vec3&);
	double GetNeedleRotation();
	void SetNeedleRotation(double);
	const glm::vec3& GetNeedleSize() const;
	void SetNeedleSize(const glm::vec3&);
	void CalculateRanges();

};
#endif
