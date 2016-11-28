/*
 * Component.cpp
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#include <Component.h>

namespace gtfx {

Component::Component() {
	// TODO Auto-generated constructor stub

}

void Component::Update(double gameTime) {
}

bool Component::GetIsEnabled() const {
	return mIsEnabled;
}

void Component::SetIsEnabled(bool isEnabled) {
	mIsEnabled = isEnabled;
}

Component::~Component() {
	// TODO Auto-generated destructor stub
}

} /* namespace gtfx */
