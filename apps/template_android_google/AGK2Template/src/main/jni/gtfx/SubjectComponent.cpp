/*
 * SubjectComponent.cpp
 *
 *  Created on: 13-Dec-2016
 *      Author: gsarwal
 */

#include "SubjectComponent.h"
#include "ListenerComponent.h"

namespace gtfx {

SubjectComponent::SubjectComponent() {
	// TODO Auto-generated constructor stub

}

const std::vector<ListenerComponent*>& SubjectComponent::GetListeners() const {
	return mListeners;
}

SubjectComponent::~SubjectComponent() {
}

void SubjectComponent::AddListener(ListenerComponent* listener) {
	if(NULL == listener) {
		printf("WARNING: listener is not defined");
		return;
	}
	mListeners.push_back(listener);
}

void SubjectComponent::RemoveListener(ListenerComponent* listener) {
	if(NULL == listener) {
		printf("WARNING: listener is not defined");
		return;
	}
}

void SubjectComponent::NotifyListeners(uint notification) {
	std::vector<ListenerComponent*>::const_iterator it = mListeners.begin();
	while(it != mListeners.end()) {
		(*it)->HandleNotification(this, notification);
	}
}

} /* namespace gtfx */

