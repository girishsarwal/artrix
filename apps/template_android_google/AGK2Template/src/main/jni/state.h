#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class State
{
public:
    virtual void oneTimeEnter() = 0;
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update(double gameTime) = 0;
};

#endif // STATE_H_INCLUDED
