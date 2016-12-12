/*
 * SwitchScreenAction.cpp
 *
 *  Created on: 09-Dec-2016
 *      Author: gsarwal
 */

#include <SwitchScreenAction.h>

namespace gtfx {

SwitchScreenAction::SwitchScreenAction() {
	SetDefaultName("SwitchScreenAction");
}

SwitchScreenAction::SwitchScreenAction(tinyxml2::XMLNode* node) {
	tinyxml2::XMLElement* element = node->ToElement();
	if(NULL == element) {
		printf("ERROR: SwitchScreenAction:: There was a problem parsing the XML Node");
		return;
	}
	mName = element->Attribute("name");
	mTarget = element->FirstChildElement("target")->FirstChild()->Value();
}

void SwitchScreenAction::Execute() {
	ViewManager::GetInstance()->ChangeView(mTarget);
}

SwitchScreenAction::~SwitchScreenAction() {
	// TODO Auto-generated destructor stub
}

} /* namespace gtfx */
