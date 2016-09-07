#ifndef _H_APP
#define _H_APP

// Include AGK libraries
#include "agk.h"
#include "artrix.h"
#include "statemanager.h"

// Global values for the app
class app
{
	public:

		Artrix *pArtrix;
		StateManager *mStateManager;

	public:

		// constructor
		app();
        ~app();

		// main app functions - mike to experiment with a derived class for this..
        void Begin( void );
        void Loop( void );
        void End( void );
};

extern app App;

#endif
