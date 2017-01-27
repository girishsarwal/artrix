#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H
#include <string>
#include <tinyxml2>
#include "GameObject.h"
#include "Command.h"
namespace gtfx {
class GameObject;
class Command;
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
}
#endif // WIDGETFACTORY_H
