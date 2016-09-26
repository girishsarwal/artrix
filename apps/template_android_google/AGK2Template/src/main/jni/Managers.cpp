#include "Managers.h"

Managers::Managers()
{
    //ctor
}

Managers::~Managers()
{
    //dtor
}
void Managers::Initialize() {
    CM = ConfigurationManager::GetInstance();

    /** rest of the managers depend on config manager **/
    SM = StateManager::GetInstance();
    MM = MetricsManager::GetInstance();
    if(MM != NULL) MM->Initialize(1920, 1080);
}
void Managers::Destroy(){
    delete(SM);
    delete(MM);
    delete(CM);
}
ConfigurationManager* Managers::CM = NULL;

StateManager* Managers::SM = NULL;
MetricsManager* Managers::MM = NULL;
