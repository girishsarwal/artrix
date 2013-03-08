/** Factory to create widgest
 * 
 * TODO: enhance mechanism to crate from abstract factory**/
#include "afx.h"
#pragma once
class WidgetFactory{
public:
	void createWidget(char* widgetType, Widget* pWidget);
};
