/*
 * Command.cpp
 *
 *  Created on: 09-Dec-2016
 *      Author: gsarwal
 */

#include "Command.h"

namespace gtfx {

Command::Command()
	: mCanExecute(true) {
	SetDefaultName("Command");

}
Command::Command(tinyxml2::XMLNode* node)
	: mCanExecute(true) {
	tinyxml2::XMLElement* element = node->ToElement();
	if(NULL == element) {
		printf("ERROR: Command:: Cannot parse command");
		return;
	}
}
bool Command::GetCanExecute() const {
	return mCanExecute;
}

void Command::Execute() {
}

void Command::AddArgument(const std::string& name, const std::string& value) {
	mArguments[name] = value;
}

void Command::SetCanExecute(bool canExecute) {
	mCanExecute = canExecute;
}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

} /* namespace gtfx */
