/*
 * SubjectComponent.h
 *
 *  Created on: 13-Dec-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_SUBJECTCOMPONENT_H_
#define INCLUDE_SUBJECTCOMPONENT_H_

#include "Component.h"

namespace gtfx {
class ListenerComponent;
class SubjectComponent:
		public Component {
private:
	std::vector<ListenerComponent*> mListeners;
public:

	SubjectComponent();
	virtual ~SubjectComponent();
	const std::vector<ListenerComponent*>& GetListeners() const;
	void AddListener(ListenerComponent* listener);
	void RemoveListener(ListenerComponent* listener);
	void NotifyListeners(uint notification);
};

} /* namespace gtfx */

#endif /* INCLUDE_SUBJECTCOMPONENT_H_ */
