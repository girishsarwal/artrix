#pragma once
#include "afx.h"
class Widget
{
public:

	bool m_bInitialized;
	AttributeSet m_asAttributes;
	
	void initialize(AttributeSet& as);
	void update(double frameTime);
	void render(double frameTime);
	Widget(void);
	~Widget(void);

protected:
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);

};

