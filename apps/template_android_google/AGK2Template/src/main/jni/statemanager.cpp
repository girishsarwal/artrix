#include "statemanager.h"
#include <android/log.h>
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
    __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "attempting change state...");
    if(NULL == sm){
        __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "cannot change state, state machine is null");
        return;
    }
    if(NULL == newState){
        __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "cannot change state, state is null");
        return;
    }
    State* state = sm->GetCurrentState();
    __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "state transition from %s to %s", (state != NULL) ? state->GetName().c_str() : "null", (newState != NULL) ? newState->GetName().c_str() : "null");
    if(NULL != state) {
        if (state->GetIsTerminable() != true){
            __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "cannot change state, current state is non-terminable");
            return;
        }
        state->Exit(sm);
    }
    sm->SetPreviousState(state);
    sm->SetCurrentState(newState);
    if(!newState->GetIsOneTimeEntered()) {
        newState->OneTimeEnter(sm);
    }
    newState->Enter(sm);
    __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "state changed to %s", newState->GetName().c_str());
}
StateManager* StateManager::m_instance = 0;
