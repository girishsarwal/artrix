#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class State
{
public:
    virtual void OneTimeEnter() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual void Update(double gameTime) = 0;
};

#endif // STATE_H_INCLUDED
