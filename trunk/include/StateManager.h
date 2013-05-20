/** State Manager
Knows how to make stuff switch states
**/
#include "afx.h"
class StateManager{
private:
	static StateManager* m_pTheStateManager;
public:
	static StateManager* getInstance();
	void initialize();
	void shutdown();
	void gotoState(ISupportsStates* attachedObject, IState* state);
	StateManager();
	~StateManager();
};

