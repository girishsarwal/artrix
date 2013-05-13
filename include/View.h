#pragma once
#include "afx.h"
class View
{
public:
	SharedAllocation<Widget*> m_Widgets;

	View();
	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void addWidget(Widget* pWidget);
	void create(AttributeSet& as);
	void enter();
	void exit();
	std::string m_sName;
protected:

	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
	virtual void onCreate();
};

