#include "artrix.h"
#include "agk.h"
using namespace AGK;
Artrix::Artrix()
{

}

Artrix::~Artrix()
{
    //dtor
}
void Artrix::Begin()
{
    agk::SetVirtualResolution (1024, 768);
    agk::SetClearColor( 151,170,204 ); // light blue
    agk::SetSyncRate(60,0);
    agk::SetScissor(0,0,0,0);


}

void Artrix::Loop()
{

}
void Artrix::End()
{
    StateManager::DestroyInstance();
}
