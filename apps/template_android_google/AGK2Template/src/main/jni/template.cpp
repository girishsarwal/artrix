// Includes
#include "template.h"
#include "Managers.h"
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
    /** let managers do the ground work **/
    Managers::CM->GenerateFactoryConfiguration();
    Managers::CM->ParseConfig("templates/config.default");
    Managers::CM->ParseScreens("templates/screens.default");

    /** begin artrix program **/
    pArtrix->Begin();
}

void app::Loop (void)
{
	pArtrix->Loop();
	agk::Sync();
}


void app::End (void)
{
    if (pArtrix) pArtrix->End();
    Managers::Destroy();
}
