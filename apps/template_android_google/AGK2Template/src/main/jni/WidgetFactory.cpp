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

void WidgetFactory::CreateWidget(const string& type, XMLNode* node, Widget** widget) {
    __android_log_print(ANDROID_LOG_DEBUG, "WidgetFactory::CreateWidget", "request for widget creation of type '%s'", type.c_str());
    if(type == "ButtonWidget") {
        __android_log_print(ANDROID_LOG_DEBUG, "WidgetFactory::CreateWidget", "'ButtonWidget' created");
        *widget = new ButtonWidget(node);
        return;
    } else if(type == "ImageWidget") {
        __android_log_print(ANDROID_LOG_DEBUG, "WidgetFactory::CreateWidget", "'ImageWidget' created");
        *widget = new ImageWidget(node);
        return;
    }
    __android_log_print(ANDROID_LOG_WARN, "WidgetFactory::CreateWidget", "factory does not understand widget of type '%s'", type.c_str());
}
void WidgetFactory::CreateWidget(const string& name, const string& type, XMLNode* node, Widget** widget) {
    CreateWidget(type, node, widget);
    (*widget)->SetName(name);
}
