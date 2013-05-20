/** State Manager
Knows how to make stuff switch states
**/
#include "afx.h"
StateManager* StateManager::getInstance(){
	if(NULL == m_pTheStateManager){
		m_pTheStateManager = new StateManager();
	};
	return m_pTheStateManager;
};
void StateManager::initialize(){
};
void StateManager::shutdown(){
};
void StateManager::gotoState(ISupportsStates* attachedObject, IState* state){
};
StateManager::StateManager(){
};
StateManager::~StateManager(){
};
StateManager* StateManager::m_pTheStateManager = NULL;

