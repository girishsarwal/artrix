#ifndef ATTITUDEINDICATORWIDGET_H
#define ATTITUDEINDICATORWIDGET_H
#include "afx.h"
#include "TelemetryWidget.h"
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
	glm::vec3 mOrientation;
	
	AttitudeIndicatorWidget();
	AttitudeIndicatorWidget(tinyxml2::XMLNode*);
	~AttitudeIndicatorWidget();
	
	const std::string& GetGimbalTexture() const;
	void SetGimbalTexture(const std::string&);
	const std::string& GetPanelTexture() const;
	void SetPanelTexture(const std::string&);
	const glm::vec3& GetOrientation() const;
	void SetOrientation(const glm::vec3&);

};
#endif
