#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "statemachine.h"
#include "state.h"
class StateManager
{
    public:

        virtual ~StateManager();
        static StateManager* GetInstance();
        static void DestroyInstance();
        void GotoState(StateMachine* sm, State* newState);
    protected:

    private:
        static StateManager* m_instance;
        StateManager();
};

#endif // STATEMANAGER_H
