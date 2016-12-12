#include "GameObjectFactory.h"


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

namespace gtfx {
GameObjectFactory::GameObjectFactory() {
    //ctor
}

GameObjectFactory::~GameObjectFactory() {
    //dtor
}

void GameObjectFactory::CreateWidget(tinyxml2::XMLNode* node, gtfx::GameObject** widget) {
    std::string type = string(node->Value());
    if(NULL != *widget){
    	printf("\nWidgetFactory::CreateWidget - Widget is not null, will be recreated!");
    }
    printf("\nWidgetFactory::CreateWidget - request for widget creation of type '%s'", type.c_str());
    if(type == "ButtonWidget") {
    	printf("\nWidgetFactory::CreateWidget - 'ButtonWidget' created");
        *widget = new ButtonWidget(node);
    } else if(type == "ImageWidget") {
		printf("\nWidgetFactory::CreateWidget - 'ImageWidget' created");
        *widget = new ImageWidget(node);
    } else if(type == "TextWidget") {
	    printf("\nWidgetFactory::CreateWidget - 'TextWidget' created");
	    *widget = new TextWidget(node);
    } else if(type == "TimerWidget") {
    	    printf("\nWidgetFactory::CreateWidget - 'TimerWidget' created");
    	    *widget = new TimerWidget(node);
    } else if(type == "AttitudeIndicatorWidget") {
	    printf("\nWidgetFactory::CreateWidget - 'AttitudeIndicator' created");
	    *widget = new AttitudeIndicatorWidget(node);
    } else if(type == "CircularGaugeWidget") {
	    printf("\nWidgetFactory::CreateWidget - 'CircularGaugeWidget' created");
	    *widget = new CircularGaugeWidget(node);
    } else {
        printf("\nWidgetFactory::CreateWidget - factory does not understand widget of type '%s'",
              type.c_str());
        return;
    }
    if(NULL == (*widget)) {
        printf("\nWidgetFactory::CreateWidget - There was a problem creating the widget type '%s'",
              type.c_str());
        return;
    }
    const char* widgetName = node->ToElement()->Attribute("name");
    if(NULL != widgetName) {
        (*widget)->SetName(string(widgetName));
    }
}


void GameObjectFactory::CreateCommand(tinyxml2::XMLNode* node, gtfx::Command** command) {
	std::string type = string(node->Value());
	if(NULL != *command){
		printf("\nCommandFactory::CreateCommand- Command is not null, will be recreated!");
	}
	printf("\nCommandFactory::CreateCommand - request for command creation of type '%s'", type.c_str());
	if(type == "SwitchScreenAction") {
		*command = new gtfx::SwitchScreenAction(node);
	} else {
		printf("\nCommandFactory::CreateCommand- factory does not understand command of type '%s'",
			  type.c_str());
		return;
	}
	if(NULL == (*command)) {
		printf("\nCommandFactory::CreateCommmand- There was a problem creating the command of type '%s'",
			  type.c_str());
		return;
	}
	const char* commandName = node->ToElement()->Attribute("name");
	if(NULL != commandName) {
		(*command)->SetName(string(commandName));
	}
}
}
