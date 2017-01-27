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

    tinyxml2::XMLDocument* initial_configuration = NULL;
    ConfigurationManager::GetInstance()->CopyMedia("media.mf", COPY_MODE_DEFAULT);
    if(NULL == initial_configuration ) {
        //TODO: Bail out saying there was a problem
        return;
    }

    /** let managers do the ground work **/
    /*Managers::CM->CopyMedia("media.manifest", COPY_MODE_DEFAULT);
    Managers::CM->ParseConfig("templates/config.default");
    Managers::CM->ParseScreens("templates/screens.default");*/

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
    //Managers::Destroy();
}
