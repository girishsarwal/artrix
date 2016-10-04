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
        return;
    } else if(type == "ImageWidget") {
        ALOGD("WidgetFactory::CreateWidget", "'ImageWidget' created");
        *widget = new ImageWidget(node);
        return;
    }
    ALOGW("WidgetFactory::CreateWidget", "factory does not understand widget of type '%s'", type.c_str());
}
void WidgetFactory::CreateWidget(const string& name, XMLNode* node, Widget** widget) {
    CreateWidget(node, widget);
    (*widget)->SetName(name);
}
