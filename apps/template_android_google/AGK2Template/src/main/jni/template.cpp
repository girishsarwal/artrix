// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

app::app(){
    pArtrix = new Artrix();
};

app::~app(){
    delete(pArtrix);
};

void app::Begin(void)
{
    /** Initialize the managers **/
    mStateManager = StateManager::GetInstance();

    /** begin artrix program **/
    pArtrix->Begin();
}

void app::Loop (void)
{
	agk::Print( agk::ScreenFPS() );
	pArtrix->Loop();
	agk::Sync();
}


void app::End (void)
{
    pArtrix->End();
}
