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
    /** Initialize the managers **/
    Managers::Initialize();
    Managers::CM->CopyMedia("media.manifest");
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
