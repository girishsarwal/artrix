#pragma once
#include "afx.h"
class ButtonWidget
	: public Widget{
private:
public:
	ButtonWidget();
	ButtonWidget(AttributeSet& attrs);
	void onInitialize();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
}
