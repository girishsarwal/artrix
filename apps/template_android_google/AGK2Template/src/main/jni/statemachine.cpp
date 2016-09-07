#include "statemachine.h"

StateMachine::StateMachine(){
    mCurrentState = 0;
    mPreviousState = 0;
}
StateMachine::~StateMachine(){
    delete(mCurrentState);
    delete(mPreviousState);
}
State* StateMachine::GetCurrentState(){
    return mCurrentState;
}
void StateMachine::SetCurrentState(State* newState){
    mCurrentState = newState;
}

State* StateMachine::GetPreviousState(){
    return mPreviousState;
}
void StateMachine::SetPreviousState(State* newState){
    mPreviousState = newState;
}
