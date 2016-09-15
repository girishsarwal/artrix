#ifndef ARTRIX_H
#define ARTRIX_H


#include "statemachine.h"
#include "screen.h"
#include "ButtonWidget.h"
#include "ConfigParser.h"

class Artrix
    : public StateMachine
{
    public:
        Artrix();
        virtual ~Artrix();

        void Begin();
        void Loop();
        void End();

    protected:

    private:

};

class ArtrixHomeState
    : public State
{
    public:
        void OneTimeEnter(StateMachine*);
        void Enter(StateMachine*);
        void Exit(StateMachine*);
        void Update(StateMachine*, double gameTime);
        ArtrixHomeState();
        ~ArtrixHomeState();
    private:
        Screen* mHomeScreen;
        ButtonWidget* mBw;

};

#endif // ARTRIX_H
