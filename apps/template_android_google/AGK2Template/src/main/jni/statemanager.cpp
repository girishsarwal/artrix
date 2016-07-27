#include "statemanager.h"
StateManager::StateManager()
{

}
StateManager::~StateManager()
{

}
StateManager* StateManager::GetInstance()
{
    if(0 == m_instance)
        m_instance = new StateManager();
    return m_instance;
}
void StateManager::DestroyInstance()
{
    delete(m_instance);
}
void StateManager::GotoState(StateMachine* sm, State* newState)
{
    if(0 == newState)
    {
        return;
    }
    State* state = sm->getCurrentState();
    if(0 != state){
        state->exit();
    }
    sm->setPreviousState(state);
    sm->setCurrentState(newState);
    newState->enter();
}
StateManager* StateManager::m_instance = 0;
