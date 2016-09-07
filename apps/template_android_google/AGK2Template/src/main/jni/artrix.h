#ifndef ARTRIX_H
#define ARTRIX_H
#include "statemachine.h"
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

class ArtrixMonitorState
    : public State
{
    public:

};

#endif // ARTRIX_H
