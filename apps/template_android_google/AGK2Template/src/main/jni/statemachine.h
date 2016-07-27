#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED
#include "state.h"
class StateMachine
{
public:
    virtual State* getCurrentState() = 0;
    virtual void setCurrentState(State*) = 0;
    virtual State* getPreviousState() = 0;
    virtual void setPreviousState(State*) = 0;
};

#endif // STATEMACHINE_H_INCLUDED
