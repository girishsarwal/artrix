#include "state.h"
void State::SetIsOneTimeEntered(bool _isOneTimeEntered){
    mIsOneTimeEntered = _isOneTimeEntered;
}

const bool State::GetIsOneTimeEntered() const {
    return mIsOneTimeEntered;
}
const bool State::GetIsTerminable() const {
    return mIsTerminable;
}
const string& State::GetName() const {
    return mName;
}

State::State(const string& name) {
    mName = name;
    mIsTerminable = true;
    mIsOneTimeEntered = false;
}
State::State(const string& name, bool isTerminable) {
    mName = name;
    mIsTerminable = isTerminable;
    mIsOneTimeEntered = false;
}
State::~State(){

}
void State::OneTimeEnter(StateMachine* sm) {
    ALOGD("State", "attempting one time entered into %s", mName.c_str());
    OnOneTimeEnter(sm);
    SetIsOneTimeEntered(true);
    ALOGD("State", "one time entered into %s", mName.c_str());
}

void State::Enter(StateMachine* sm){
    ALOGD("State", "attempting enter into %s", mName.c_str());
    OnEnter(sm);
    ALOGD("State", "entered into %s", mName.c_str());
}
void State::Exit(StateMachine* sm) {
    ALOGD("State", "attempting exit from %s", mName.c_str());
    OnExit(sm);
    ALOGD("State", "exited from %s", mName.c_str());
}
void State::OnOneTimeEnter(const StateMachine* sm) { }
void State::OnEnter(const StateMachine* sm) { }
void State::OnExit(const StateMachine* sm) { }

