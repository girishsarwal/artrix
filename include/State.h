#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include "afx.h"
#include "StateMachine.h"
class StateMachine;
class State
{
private:
	std::string mName;
    bool mIsOneTimeEntered;
    bool mIsTerminable;

public:
    void OneTimeEnter(StateMachine*);
    void Enter(StateMachine*);
    void Exit(StateMachine*);
    virtual void Update(const StateMachine*, double gameTime) = 0;

    const std::string& GetName() const;
    const bool GetIsOneTimeEntered() const;
    const bool GetIsTerminable() const;

    void SetIsOneTimeEntered(bool);

    State(const std::string&);
    State(const std::string&, bool);
    ~State();

protected:
    virtual void OnOneTimeEnter(const StateMachine*);
    virtual void OnEnter(const StateMachine*);
    virtual void OnExit(const StateMachine*);
};

#endif // STATE_H_INCLUDED
