#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include "statemachine.h"
#include <string>
#include <android/log.h>
using namespace std;
class StateMachine;
class State
{
private:
    string mName;
    bool mIsOneTimeEntered;
    bool mIsTerminable;

public:
    void OneTimeEnter(StateMachine*);
    void Enter(StateMachine*);
    void Exit(StateMachine*);
    virtual void Update(const StateMachine*, double gameTime) = 0;

    string& GetName();
    bool GetIsOneTimeEntered();
    bool GetIsTerminable();
    void SetIsOneTimeEntered(bool);

    State(const string&);
    State(const string&, bool);
    ~State();

protected:
    virtual void OnOneTimeEnter(const StateMachine*);
    virtual void OnEnter(const StateMachine*);
    virtual void OnExit(const StateMachine*);
};

#endif // STATE_H_INCLUDED
