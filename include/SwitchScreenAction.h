/*
 * SwitchScreenAction.h
 *
 *  Created on: 09-Dec-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_SWITCHSCREENACTION_H_
#define INCLUDE_SWITCHSCREENACTION_H_

#include "Command.h"
#include "ViewManager.h"
namespace gtfx {

class SwitchScreenAction: public Command {
private:
	std::string mTarget;
public:
	SwitchScreenAction();
	SwitchScreenAction(tinyxml2::XMLNode* node);
	void Execute();
	virtual ~SwitchScreenAction();
};

} /* namespace gtfx */

#endif /* INCLUDE_SWITCHSCREENACTION_H_ */
