#pragma once
#include "afx.h"
#include "KeyManageable.h"
#include "Widget.h"
#include "WidgetFactory.h"
class View
	: public KeyManageable
{
public:
	vector<Widget*> mWidgets;
	View();
	View(tinyxml2::XMLNode*);

	virtual ~View(void);

	void Update(double frameTime);
	void AddWidget(Widget* pWidget);
	void initialize();
	
protected:
	
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
};

