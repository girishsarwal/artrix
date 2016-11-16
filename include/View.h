#pragma once
#include "afx.h"
#include "KeyManageable.h"
#include "Widget.h"
#include "WidgetFactory.h"
class View
	: public KeyManageable
{
public:
	vector<Widget*> m_Widgets;
	View();
	View(tinyxml2::XMLNode*);

	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void AddWidget(Widget* pWidget);
	void initialize();
	
protected:
	
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
};

