#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H
#include "afx.h"
#include "UIWidget.h"
namespace gtfx {
class ButtonWidget
	: public UIWidget{
private:

public:
	ButtonWidget();
	ButtonWidget(tinyxml2::XMLNode*);
	~ButtonWidget();

	void OnInitialize();
	bool ValidateAttributes();
	void OnRender(double frameTime);
};
}
#endif
