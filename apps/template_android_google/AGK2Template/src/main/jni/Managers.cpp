#include "Managers.h"

Managers::Managers()
{
    //ctor
}

Managers::~Managers()
{
    //dtor
}
void Managers::Initialize(ANativeActivity* activity) {
    CM = ConfigurationManager::GetInstance();
    if(NULL == CM){
        ALOGE("FATAL", "cannot create ConfigurationManager");
        return;
    }
    CM->Initialize(activity);
    /** rest of the managers depend on config manager **/
    MM = MetricsManager::GetInstance();
    if(MM == NULL) {
        ALOGE("FATAL", "cannot create MetricsManager");
        return;
    }
    /** TODO: read the dimension from configuration manager **/
    float width = 1920;
    float height = 1080;

    MM->Initialize(width, height);
    SM = StateManager::GetInstance();
}
void Managers::Destroy(){
    delete(SM);
    delete(MM);
    delete(CM);
}
ConfigurationManager* Managers::CM = NULL;

StateManager* Managers::SM = NULL;
MetricsManager* Managers::MM = NULL;
