#include "afx.h"
void WidgetFactory::createWidget(char* pWidgetType, Widget** pWidget, AttributeSet& as){
	if(NULL != *pWidget){
		printf("WARNING: Widget is not NULL, will be recreated!\n");
	}
	printf("WidgetFactory: Request for widget creation '%s' ", pWidgetType);
	as.display();
	if(0 == strcmp(pWidgetType, "ImageWidget")){
		*pWidget = new ImageWidget();
		printf("ImageWidget created\n");	

	}
	if(0 == strcmp(pWidgetType, "AttitudeIndicatorWidget")){
		*pWidget = new AttitudeIndicatorWidget();
		printf("AttitudeIndicatorWidget created\n");	

	}
	if(0 == strcmp(pWidgetType, "TextWidget")){
		*pWidget = new TextWidget();
		printf("Textwidget created\n");
	}
	if(0 == strcmp(pWidgetType, "TimerWidget")){
		*pWidget = new TimerWidget();
		printf("Textwidget created\n");
	}
}
