#include "afx.h"
#pragma once
class ISupportsStates{
	public:
		virtual IState* getState() = 0;
		virtual void setState(IState* state) = 0;
		virtual IState* getPreviousState() = 0;
		virtual void setPreviousState(IState* state) = 0;
};
