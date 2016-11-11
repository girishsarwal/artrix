#include "State.h"
void State::SetIsOneTimeEntered(bool _isOneTimeEntered){
    mIsOneTimeEntered = _isOneTimeEntered;
}

const bool State::GetIsOneTimeEntered() const {
    return mIsOneTimeEntered;
}
const bool State::GetIsTerminable() const {
    return mIsTerminable;
}
const std::string& State::GetName() const {
    return mName;
}

State::State(const std::string& name) {
    mName = name;
    mIsTerminable = true;
    mIsOneTimeEntered = false;
}
State::State(const std::string& name, bool isTerminable) {
    mName = name;
    mIsTerminable = isTerminable;
    mIsOneTimeEntered = false;
}
State::~State(){

}
void State::OneTimeEnter(StateMachine* sm) {
    printf("State - attempting one time entered into %s", mName.c_str());
    OnOneTimeEnter(sm);
    SetIsOneTimeEntered(true);
    printf("State- one time entered into %s", mName.c_str());
}

void State::Enter(StateMachine* sm){
    printf("State - attempting enter into %s", mName.c_str());
    OnEnter(sm);
    printf("State - entered into %s", mName.c_str());
}
void State::Exit(StateMachine* sm) {
	printf("State - attempting exit from %s", mName.c_str());
    OnExit(sm);
    printf("State - exited from %s", mName.c_str());
}
void State::OnOneTimeEnter(const StateMachine* sm) { }
void State::OnEnter(const StateMachine* sm) { }
void State::OnExit(const StateMachine* sm) { }
