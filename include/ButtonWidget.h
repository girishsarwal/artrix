#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H
#include "afx.h"
#include "UIWidget.h"
class ButtonWidget
	: public UIWidget{
private:
public:
	ButtonWidget();
	ButtonWidget(tinyxml2::XMLNode*);
	~ButtonWidget();
	void onInitialize();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
};
#endif
