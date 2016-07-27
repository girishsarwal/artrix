// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
    a = new Artrix();
	agk::SetVirtualResolution (1024, 768);
    agk::SetClearColor( 151,170,204 ); // light blue
    agk::SetSyncRate(60,0);
    agk::SetScissor(0,0,0,0);

    a->begin();
}

void app::Loop (void)
{
	agk::Print( agk::ScreenFPS() );
	agk::Sync();
}


void app::End (void)
{
    a->shutdown();
}
