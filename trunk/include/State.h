#include "afx.h"
#pragma once
class IState{
	public:
		virtual void enter(ISupportsStates* attachedObject) = 0;
		virtual void update(ISupportsStates* attachedObject, double frameTime) = 0;
		virtual void exit(ISupportsStates* attachedObject) = 0;
};
template <class T> 
class State {
	private:
	ISupportsStates* m_pObject;
	public:
		void enter(ISupportsStates* attachedObject){
		};
		void update(ISupportsStates* attachedObject, double frameTime){
		};
		void exit(ISupportsStates* attachedObject){
		};
};

