#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED
#include "state.h"
class Standate;
class StateMachine
{
private:orid
    State*  mCurrentState;
    State*  mPreviousState;

public:
    State* GetCurrentState();
    void SetCurrentState(State*);
    State* GetPreviousState();
    void SetPreviousState(State*);

    StateMachine();
    ~StateMachine();
};

#endif // STATEMACHINE_H_INCLUDED
