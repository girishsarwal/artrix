#pragma once
#include "afx.h"
class View
{
public:
	SharedAllocation<Widget*> m_Widgets;
	std::string m_sName;
	
	View();
	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void addWidget(Widget* pWidget);
	void initialize(AttributeSet& as);
	
protected:
	
	virtual void onInitialize(AttributeSet& as);
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
};

