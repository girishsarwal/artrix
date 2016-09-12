#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include "statemachine.h"
class StateMachine;
class State
{
private:
    bool isOneTimeEntered;
public:
    virtual void OneTimeEnter(StateMachine *sm) = 0;
    virtual void Enter(StateMachine *sm) = 0;
    virtual void Exit(StateMachine *sm) = 0;
    virtual void Update(StateMachine* sm, double gameTime) = 0;
    bool GetIsOneTimeEntered();
    void SetIsOneTimeEntered(bool);

};

#endif // STATE_H_INCLUDED
