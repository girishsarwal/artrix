#include "WidgetFactory.h"
#include <android/log.h>
#include "ButtonWidget.h"
#include "ImageWidget.h"
WidgetFactory::WidgetFactory() {
    //ctor
}

WidgetFactory::~WidgetFactory() {
    //dtor
}

void WidgetFactory::CreateWidget(XMLNode* node, Widget** widget) {
    string type = string(node->Value());
    ALOGD("WidgetFactory::CreateWidget", "request for widget creation of type '%s'", type.c_str());
    if(type == "ButtonWidget") {
        ALOGD("WidgetFactory::CreateWidget", "'ButtonWidget' created");
        *widget = new ButtonWidget(node);
    } else if(type == "ImageWidget") {
        ALOGD("WidgetFactory::CreateWidget", "'ImageWidget' created");
        *widget = new ImageWidget(node);
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