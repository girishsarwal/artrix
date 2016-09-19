#include "state.h"
void State::SetIsOneTimeEntered(bool _isOneTimeEntered){
    mIsOneTimeEntered = _isOneTimeEntered;
}

bool State::GetIsOneTimeEntered(){
    return mIsOneTimeEntered;
}
bool State::GetIsTerminable() {
    return mIsTerminable;
}
string& State::GetName(){
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
    __android_log_print(ANDROID_LOG_DEBUG, "State", "attempting one time entered into %s", mName.c_str());
    OnOneTimeEnter(sm);
    SetIsOneTimeEntered(true);
    __android_log_print(ANDROID_LOG_DEBUG, "State", "one time entered into %s", mName.c_str());
}

void State::Enter(StateMachine* sm){
    __android_log_print(ANDROID_LOG_DEBUG, "State", "attempting enter into %s", mName.c_str());
    OnEnter(sm);
    __android_log_print(ANDROID_LOG_DEBUG, "State", "entered into %s", mName.c_str());
}
void State::Exit(StateMachine* sm) {
    __android_log_print(ANDROID_LOG_DEBUG, "State", "attempting exit from %s", mName.c_str());
    OnExit(sm);
    __android_log_print(ANDROID_LOG_DEBUG, "State", "exited from %s", mName.c_str());
}
void State::OnOneTimeEnter(const StateMachine* sm) { }
void State::OnEnter(const StateMachine* sm) { }
void State::OnExit(const StateMachine* sm) { }

