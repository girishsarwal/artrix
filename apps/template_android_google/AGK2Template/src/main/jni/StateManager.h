#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <android/log.h>
#include "statemachine.h"
#include "state.h"
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

#endif // STATEMANAGER_H
