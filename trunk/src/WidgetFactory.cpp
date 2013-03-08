#include "afx.h"
void WidgetFactory::createWidget(char* pWidgetType, Widget* pWidget){
	if(0 == strcmp(pWidgetType, "ImageWidget")){
		pWidget = new ImageWidget();
	}
}
