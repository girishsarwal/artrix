#include "state.h"
void State::SetIsOneTimeEntered(bool _isOneTimeEntered){
    isOneTimeEntered = _isOneTimeEntered;
}

bool State::GetIsOneTimeEntered(){
    return isOneTimeEntered;
}
string& State::GetName(){
    return mName;
}
State::State(const string& name){
    mName = name;
}
State::~State(){
}
