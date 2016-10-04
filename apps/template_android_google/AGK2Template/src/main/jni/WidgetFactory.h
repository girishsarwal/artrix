#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H
#include <vector>
#include "widget.h"

using namespace std;
class WidgetFactory
{
    public:
        WidgetFactory();
        virtual ~WidgetFactory();
        static void CreateWidget(XMLNode*, Widget**);
        static void CreateWidget(const string&, XMLNode*, Widget**);
    protected:
    private:
};

#endif // WIDGETFACTORY_H
