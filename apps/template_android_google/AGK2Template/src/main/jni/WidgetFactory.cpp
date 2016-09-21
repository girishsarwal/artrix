#include "WidgetFactory.h"

#include "ButtonWidget.h"
WidgetFactory::WidgetFactory()
{
    //ctor
}

WidgetFactory::~WidgetFactory()
{
    //dtor
}

void WidgetFactory::CreateWidget(const string& type, const vector<WidgetAttribute*>& attributes, Widget** widget) {
    if(type.compare("ButtonWidget")) {
        *widget = new ButtonWidget(attributes);
    }
}
void WidgetFactory::CreateWidget(const string& name, const string& type, const vector<WidgetAttribute*>&, Widget** widget) {
}
