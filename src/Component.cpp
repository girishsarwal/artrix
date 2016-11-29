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

bool Component::GetIsEnabled() const {
	return mIsEnabled;
}

void Component::SetIsEnabled(bool isEnabled) {
	mIsEnabled = isEnabled;
}

Component::~Component() {
	// TODO Auto-generated destructor stub
}






bool Component::GetIsInitialized() const {
    return mIsInitialized;
}
void Component::Initialize() {
    OnBeforeInitialize();

    OnInitialize();             /** we let the dervied class function execute first **/
    mIsInitialized = true;

    OnAfterInitialize();
}



void Component::BeforeInitialize() {
    OnBeforeInitialize();
}
void Component::AfterInitialize() {
	OnAfterInitialize();
}



void Component::Update(double gameTime) {
	if(!mIsInitialized){
		Initialize();
	}
    OnUpdate(gameTime);
}

void Component::BeforeDestroy() {
	OnBeforeDestroy();
}
void Component::Destroy() {
	BeforeDestroy();
	mIsInitialized = false;
	AfterDestroy();
}
void Component::AfterDestroy() {
	OnAfterDestroy();
}

void Component::OnBeforeInitialize() { }
void Component::OnInitialize() { }
void Component::OnAfterInitialize() {  }
void Component::OnBeforeUpdate(double gameTime) { }
void Component::OnUpdate(double gameTime) { }
void Component::OnAfterUpdate(double gameTime) { }
void Component::OnBeforeDestroy() { }
void Component::OnDestroy() { }
void Component::OnAfterDestroy() { }


bool Component::ValidateAttributes() { return true; }

} /* namespace gtfx */
