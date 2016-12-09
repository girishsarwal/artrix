/*
 * Command.h
 *
 *  Created on: 09-Dec-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_COMMAND_H_
#define INCLUDE_COMMAND_H_
#include "afx.h"
#include "KeyManageable.h"
namespace gtfx {

class Command
	: public KeyManageable {
private:
	bool mCanExecute;
	std::map<string, string> mArguments;
public:
	virtual void Execute();
	void AddArgument(const std::string& name, const std::string& value);
	Command();
	Command(tinyxml2::XMLNode*);
	virtual ~Command();
	bool GetCanExecute() const;
	void SetCanExecute(bool canExecute);
};

} /* namespace gtfx */

#endif /* INCLUDE_COMMAND_H_ */
