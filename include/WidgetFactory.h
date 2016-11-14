#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H
#include "afx.h"
#include "Widget.h"

class ButtonWidget;
class ImageWidget;
class TextWidget;

#include "Widget.h"
#include "ButtonWidget.h"
#include "ImageWidget.h"
#include "TextWidget.h"

#include "TimerWidget.h"

#include "CircularGaugeWidget.h"
#include "AttitudeIndicatorWidget.h"
#include "FlapsWidget.h"



class WidgetFactory
{
    public:
        WidgetFactory();
        virtual ~WidgetFactory();
        static void CreateWidget(tinyxml2::XMLNode*, Widget**);
    protected:
    private:
};

#endif // WIDGETFACTORY_H
