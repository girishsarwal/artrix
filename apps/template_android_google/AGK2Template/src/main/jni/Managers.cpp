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
    SM = StateManager::GetInstance();
}
StateManager* Managers::SM = NULL;
