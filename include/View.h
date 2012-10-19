#pragma once
#include "artrix-includes.h"
class View
{
public:
	short m_nWidgetCount;
	Widget* pWidgets[MAX_WIDGETS];
	void addWidget(Widget* _pWidget);
	void removeWidget(Widget* _pWidget);

	View(void);
	virtual ~View(void);

	void update();
	void render();
	void create();
protected:

	virtual void onUpdate();
	virtual void onRender();
	virtual void onCreate() = 0;



};

