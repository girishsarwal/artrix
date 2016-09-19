#include "artrix.h"
#include "agk.h"
#include "ButtonWidget.h"
#include "statemanager.h"
#include <android/log.h>
using namespace AGK;
Artrix::Artrix(){

}

Artrix::~Artrix(){
    //dtor
}
void Artrix::Begin()
{
    agk::SetVirtualResolution (1024, 768);
    agk::SetClearColor( 0, 0, 0); // black
    agk::SetSyncRate(60,0);
    agk::SetScissor(0,0,0,0);
    StateManager::GetInstance()->GotoState(this, new ArtrixHomeState());
}

void Artrix::Loop()
{
    mCurrentState->Update(this, 0);
}
void Artrix::End()
{
}

ArtrixHomeState::ArtrixHomeState()
    : State("Home"){
        mBw = 0;
}


ArtrixHomeState::~ArtrixHomeState(){
}

void ArtrixHomeState::OnOneTimeEnter(const StateMachine* sm)
{
    Configuration::ParseScreen("templates/home.screen", 0);
    mHomeScreen  = new Screen();
    mBw = new ButtonWidget(Vector2(100, 0), Vector2(100, 100), std::string("pilot"), std::string("buttons/blue-bar.png"));
    mBw->SetSize(100, 50);
    mHomeScreen->AddWidget(mBw);
}

void ArtrixHomeState::Update(const StateMachine* sm, double gameTime){
    mBw->Print();
}
