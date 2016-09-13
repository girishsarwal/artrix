#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include "statemachine.h"
#include <string>
using namespace std;
class StateMachine;
class State
{
private:
    string mName;
    bool isOneTimeEntered;

public:
    virtual void OneTimeEnter(StateMachine *sm) = 0;
    virtual void Enter(StateMachine *sm) = 0;
    virtual void Exit(StateMachine *sm) = 0;
    virtual void Update(StateMachine* sm, double gameTime) = 0;
    string& GetName();
    bool GetIsOneTimeEntered();
    void SetIsOneTimeEntered(bool);
    State(const string&);
    ~State();
};

#endif // STATE_H_INCLUDED
