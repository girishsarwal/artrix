#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H
#include <vector>
#include "widget.h"
#include "WidgetAttribute.h"

using namespace std;
class WidgetFactory
{
    public:
        WidgetFactory();
        virtual ~WidgetFactory();
        static void CreateWidget(const string&, const vector<WidgetAttribute*>&, Widget**);
        static void CreateWidget(const string&, const string&, const vector<WidgetAttribute*>&, Widget**);
    protected:
    private:
};

#endif // WIDGETFACTORY_H
