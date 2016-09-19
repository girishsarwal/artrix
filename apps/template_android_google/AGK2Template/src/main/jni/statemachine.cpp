#include "statemachine.h"
StateMachine::StateMachine(){
    mCurrentState = NULL;
    mPreviousState = NULL;
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
