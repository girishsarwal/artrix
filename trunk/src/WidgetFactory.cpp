#include "afx.h"
void WidgetFactory::createWidget(char* pWidgetType, Widget** pWidget){
	if(NULL != pWidget){
		printf("WARNING: Widget is not NULL, will be recreated!\n");
	}
	printf("WidgetFactory: Request for widget creation '%s'\n", pWidgetType);
	if(0 == strcmp(pWidgetType, "ImageWidget")){
		printf("ImageWidget created\n");	
		*pWidget = new ImageWidget();
	}
}
