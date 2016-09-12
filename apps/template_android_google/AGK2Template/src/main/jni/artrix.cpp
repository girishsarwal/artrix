#include "artrix.h"
#include "agk.h"
#include "ButtonWidget.h"
#include "statemanager.h"
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
    StateManager::GetInstance()->GotoState(this, new ArtrixHomeState());
}

void Artrix::Loop()
{
    agk::Print("Looping");

}
void Artrix::End()
{
    agk::Print("Ending");
}

void ArtrixHomeState::Enter(StateMachine* sm)
{

}

void ArtrixHomeState::OneTimeEnter(StateMachine* sm)
{
    mHomeScreen  = new Screen();
    ButtonWidget* bw = new ButtonWidget();
    mHomeScreen->AddWidget(bw);
}

void ArtrixHomeState::Exit(StateMachine* sm)
{
}
void ArtrixHomeState::Update(StateMachine* sm, double gameTime)
{
}
