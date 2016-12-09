#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED
#include "afx.h"
#include "State.h"
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
