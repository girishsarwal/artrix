#include "WidgetFactory.h"
#include <android/log.h>
#include "ButtonWidget.h"
WidgetFactory::WidgetFactory()
{
    //ctor
}

WidgetFactory::~WidgetFactory()
{
    //dtor
}

void WidgetFactory::CreateWidget(const string& type, XMLNode* node, Widget** widget) {
    __android_log_print(ANDROID_LOG_DEBUG, "WidgetFactory::CreateWidget", "Request for widget creation of type %s", type.c_str());
    if(type == "ButtonWidget") {
        __android_log_print(ANDROID_LOG_DEBUG, "WidgetFactory::CreateWidget", "Creating ButtonWidget");
        *widget = new ButtonWidget(node);
    }
}
void WidgetFactory::CreateWidget(const string& name, const string& type, XMLNode* node, Widget** widget) {
}
