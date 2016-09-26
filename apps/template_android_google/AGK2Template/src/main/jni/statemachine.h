#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED
#include <android/log.h>
#include "state.h"
#include "StateManager.h"
class State;
class StateMachine
{
protected:
    State*  mCurrentState;
    State*  mPreviousState;

    State*  mBlipState;
public:
    State* GetCurrentState();
    void SetCurrentState(State*);
    State* GetPreviousState();
    void SetPreviousState(State*);

    void GotoState(State*);

    StateMachine();
    ~StateMachine();
};

#endif // STATEMACHINE_H_INCLUDED
