#include "WidgetFactory.h"

WidgetFactory::WidgetFactory()
{
    //ctor
}

WidgetFactory::~WidgetFactory()
{
    //dtor
}

void WidgetFactory::CreateWidget(const string&, const vector<WidgetAttribute*>& attributes, Widget** widget) {
    if(widget == 0) {
        //memory allocation code
    }
}
void WidgetFactory::CreateWidget(const string&, const string&, const vector<WidgetAttribute*>&, Widget** widget) {
    if(widget == 0) {
        //memory allocation code
    }
}
