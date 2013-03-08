#pragma once
#include "afx.h"
class View
{
public:
	short m_nWidgetCount;
	Widget* pWidgets[MAX_WIDGETS];
	void addWidget(Widget* _pWidget);
	void removeWidget(Widget* _pWidget);

	View(void);
	virtual ~View(void);

	void update(double frameTime);
	void render(double frameTime);
	void create();
protected:

	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
	virtual void onCreate() = 0;



};

