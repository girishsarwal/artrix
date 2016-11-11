#pragma once
#include "afx.h"
#include "KeyedManager.h"
#include "Widget.h"
class View
{
public:
	KeyedManager<Widget*> m_Widgets;
	std::string m_sName;
	
	View();
	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void addWidget(Widget* pWidget);
	void initialize(tinyxml2::XMLNode*);
	
protected:
	
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
};

