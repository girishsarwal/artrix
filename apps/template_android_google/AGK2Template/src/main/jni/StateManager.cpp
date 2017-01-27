#include "StateManager.h"
#include "StateMachine.h"
#include "State.h"
namespace gtfx {
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
    if(NULL == sm){
        __android_log_print(ANDROID_LOG_VERBOSE, "StateManager", "GotoState - cannot change state, state machine is null");
        return;
    }
    sm->GotoState(newState);
}
StateManager* StateManager::m_instance = NULL;
}
