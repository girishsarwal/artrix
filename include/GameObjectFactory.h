#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H
#include "GameObject.h"
#include "afx.h"

class ButtonWidget;
class ImageWidget;
class TextWidget;

#include "GameObject.h"
#include "ButtonWidget.h"
#include "ImageWidget.h"
#include "TextWidget.h"

#include "TimerWidget.h"

#include "CircularGaugeWidget.h"
#include "AttitudeIndicatorWidget.h"
#include "FlapsWidget.h"

#include "Command.h"
#include "SwitchScreenAction.h"

class GameObjectFactory
{
    public:
		GameObjectFactory();
        virtual ~GameObjectFactory();
        static void CreateWidget(tinyxml2::XMLNode*, gtfx::GameObject**);
        static void CreateCommand(tinyxml2::XMLNode*, gtfx::Command**);
    protected:
    private:
};

#endif // WIDGETFACTORY_H
