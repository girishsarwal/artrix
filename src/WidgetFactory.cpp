#include "WidgetFactory.h"

WidgetFactory::WidgetFactory() {
    //ctor
}

WidgetFactory::~WidgetFactory() {
    //dtor
}

void WidgetFactory::CreateWidget(tinyxml2::XMLNode* node, Widget** widget) {
    std::string type = string(node->Value());
    if(NULL != *widget){
    	printf("\nWidgetFactory::CreateWidget - Widget is not null, will be recreated!");
    }
    printf("\nWidgetFactory::CreateWidget - request for widget creation of type '%s'", type.c_str());
    if(type == "ButtonWidget") {
    	printf("\nWidgetFactory::CreateWidget - 'ButtonWidget' created");
        *widget = new ButtonWidget(node);
    } else if(type == "ImageWidget") {
		printf("\nWidgetFactory::CreateWidget - 'ImageWidget' created");
        *widget = new ImageWidget(node);
    } else if(type == "TextWidget") {
	    printf("\nWidgetFactory::CreateWidget - 'TextWidget' created");
	    *widget = new TextWidget(node);
    } else if(type == "TimerWidget") {
    	    printf("\nWidgetFactory::CreateWidget - 'TimerWidget' created");
    	    *widget = new TimerWidget(node);
    } else if(type == "AttitudeIndicatorWidget") {
	    printf("\nWidgetFactory::CreateWidget - 'AttitudeIndicator' created");
	    *widget = new AttitudeIndicatorWidget(node);
    } else if(type == "CircularGaugeWidget") {
	    printf("\nWidgetFactory::CreateWidget - 'CircularGaugeWidget' created");
	    *widget = new CircularGaugeWidget(node);
    } else {
        printf("\nWidgetFactory::CreateWidget - factory does not understand widget of type '%s'",
              type.c_str());
        return;
    }
    if(NULL == (*widget)) {
        printf("\nWidgetFactory::CreateWidget - There was a problem creating the widget type '%s'",
              type.c_str());
        return;
    }
    const char* widgetName = node->ToElement()->Attribute("name");
    if(NULL != widgetName) {
        (*widget)->SetName(string(widgetName));
    }
}
