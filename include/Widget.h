#pragma once
#include "afx.h"
class Widget
{
public:

	bool m_bInitialized;
	AttributeSet m_asAttributes;
	
	virtual void initialize(AttributeSet& as) = 0;
	virtual void update(double frameTime) = 0;
	virtual void render(double frameTime) = 0;
	
	Widget(void);
	~Widget(void);
};

