/*
 * ListenerComponent.h
 *
 *  Created on: 13-Dec-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_LISTENERCOMPONENT_H_
#define INCLUDE_LISTENERCOMPONENT_H_

#include "Component.h"

namespace gtfx {
class SubjectComponent;
class ListenerComponent: public Component {
private:

public:
	void HandleNotification(SubjectComponent* mSubject, uint notification);
	void RegisterWithSubject(SubjectComponent* mSubject);
	void UnregisterWithSubject(SubjectComponent* mSubject);
	ListenerComponent();
	virtual ~ListenerComponent();
};

} /* namespace gtfx */

#endif /* INCLUDE_LISTENERCOMPONENT_H_ */
