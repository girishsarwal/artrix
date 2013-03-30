#pragma once
#include "afx.h"
class View
{
public:
	SharedAllocation<Widget*> m_Widgets;

	View(void);
	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void addWidget(Widget* pWidget);
	void create();
protected:

	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
	virtual void onCreate();



};

