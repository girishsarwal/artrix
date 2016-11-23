#ifndef ATTITUDEINDICATORWIDGET_H
#define ATTITUDEINDICATORWIDGET_H
#include "afx.h"
#include "TelemetryWidget.h"
#include "Vector3.h"
class AttitudeIndicatorWidget :
	public TelemetryWidget{
private:
	GLUquadricObj*	m_Gimbal;

protected:
	void OnInitialize();
	void OnRender(double);
	void OnInitializeSensors();
	void OnGetValuesFromSensors();
	bool ValidateAttributes();
public:
	std::string mGimbalTexture;
	std::string mPanelTexture;
	Vector3 mOrientation;
	
	AttitudeIndicatorWidget();
	AttitudeIndicatorWidget(tinyxml2::XMLNode*);
	~AttitudeIndicatorWidget();
	
	const std::string& GetGimbalTexture() const;
	void SetGimbalTexture(const std::string&);
	const std::string& GetPanelTexture() const;
	void SetPanelTexture(const std::string&);
	const Vector3& GetOrientation() const;
	void SetOrientation(const Vector3&);

};
#endif
