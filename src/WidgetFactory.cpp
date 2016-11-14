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
    	ALOGD("WidgetFactory::CreateWidget",  "Widget is not null, will be recreated!");
    }
    ALOGD("WidgetFactory::CreateWidget", "request for widget creation of type '%s'", type.c_str());
    if(type == "ButtonWidget") {
        ALOGD("WidgetFactory::CreateWidget", "'ButtonWidget' created");
        *widget = new ButtonWidget(node);
    } else if(type == "ImageWidget") {
        ALOGD("WidgetFactory::CreateWidget", "'ImageWidget' created");
        *widget = new ImageWidget(node);
    } else if(type == "TextWidget") {
	    ALOGD("WidgetFactory::CreateWidget", "'TextWidget' created");
	    *widget = new TextWidget(node);
    } else if(type == "TimerWidget") {
    	    ALOGD("WidgetFactory::CreateWidget", "'TimerWidget' created");
    	    *widget = new TimerWidget(node);
    } else if(type == "AttitudeIndicatorWidget") {
	    ALOGD("WidgetFactory::CreateWidget", "'AttitudeIndicator' created");
	    *widget = new AttitudeIndicatorWidget(node);
    } else if(type == "CircularGaugeWidget") {
	    ALOGD("WidgetFactory::CreateWidget", "'CircularGaugeWidget' created");
	    *widget = new CircularGaugeWidget(node);
    } else {
        ALOGW("WidgetFactory::CreateWidget", "factory does not understand widget of type '%s'",
              type.c_str());
        return;
    }
    if(NULL == (*widget)) {
        ALOGW("WidgetFactory::CreateWidget", "There was a problem creating the widget type '%s'",
              type.c_str());
        return;
    }
    const char* widgetName = node->ToElement()->Attribute("name");
    if(NULL != widgetName) {
        (*widget)->SetName(string(widgetName));
    }
}
