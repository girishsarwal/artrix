#include "artrix.h"
#include "agk.h"
#include "ButtonWidget.h"
#include "statemanager.h"
#include <android/log.h>
#include <algorithm>
using namespace AGK;
using namespace std;
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

}


ArtrixHomeState::~ArtrixHomeState(){
}

void ArtrixHomeState::OnOneTimeEnter(const StateMachine* sm)
{
    vector<Screen*> screens = Configuration::GetScreens();
    Screen* s = new Screen("home");
    vector<Screen*>::iterator screen = std::find(screens.begin(), screens.end(), s);
    mHomeScreen = *screen;
}

void ArtrixHomeState::Update(const StateMachine* sm, double gameTime){

}
