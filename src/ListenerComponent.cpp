/*
 * ListenerComponent.cpp
 *
 *  Created on: 13-Dec-2016
 *      Author: gsarwal
 */

#include "ListenerComponent.h"
#include "SubjectComponent.h"
namespace gtfx {

ListenerComponent::ListenerComponent() {
	// TODO Auto-generated constructor stub

}

void ListenerComponent::HandleNotification(SubjectComponent* mSubject,
		uint notification) {
}

void ListenerComponent::RegisterWithSubject(SubjectComponent* mSubject) {
	mSubject->AddListener(this);
}

void ListenerComponent::UnregisterWithSubject(SubjectComponent* mSubject) {
	mSubject->RemoveListener(this);
}

ListenerComponent::~ListenerComponent() {
	// TODO Auto-generated destructor stub
}

} /* namespace gtfx */
