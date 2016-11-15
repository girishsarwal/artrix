#pragma once
#include "afx.h"
#include "KeyManageable.h"
#include "Widget.h"
class View
	: public KeyManageable
{
public:
	vector<Widget*> m_Widgets;
	
	View();
	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void addWidget(Widget* pWidget);
	void initialize();
	
protected:
	
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
};

