#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "StateMachine.h"
#include "State.h"
namespace gtfx {
class StateMachine;
class State;
class StateManager
{
    public:
        virtual ~StateManager();
        static StateManager* GetInstance();
        static void DestroyInstance();
        void GotoState(StateMachine*, State*);
    protected:

    private:
        static StateManager* m_instance;
        StateManager();
};
}
#endif // STATEMANAGER_H
