#include "afx.h"
void WidgetFactory::createWidget(char* pWidgetType, Widget** pWidget, AttributeSet& as){
	if(NULL != *pWidget){
		printf("WARNING: Widget is not NULL, will be recreated!\n");
	}
	printf("WidgetFactory: Request for widget creation '%s'\n", pWidgetType);
	if(0 == strcmp(pWidgetType, "ImageWidget")){
		*pWidget = new ImageWidget(as);
		printf("ImageWidget created\n");	

	}
}
