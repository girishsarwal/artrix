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
    agk::SetClearColor( 128, 128, 128); // black
    agk::SetSyncRate(60,0);
    agk::SetScissor(0,0,0,0);
    StateManager::GetInstance()->GotoState(this, new ArtrixHomeState());
}

void Artrix::Loop()
{
    agk::Print("This is a sample!");
    agk::Print(mCurrentState->GetName().c_str());
    mCurrentState->Update(this, 0);
}
void Artrix::End()
{
    agk::Print("Ending");
}

ArtrixHomeState::ArtrixHomeState()
    : State("Home"){
        mBw = 0;
}


ArtrixHomeState::~ArtrixHomeState(){
}

void ArtrixHomeState::OnOneTimeEnter(const StateMachine* sm)
{
//    //ConfigParser::ParseScreen("templates/home.screen", 0);
    mHomeScreen  = new Screen();
    __android_log_print(ANDROID_LOG_DEBUG, "ArtrixHomeState", "1");
    mBw = new ButtonWidget(Vector2(100, 0), Vector2(100, 100), std::string("pilot"), std::string("buttons/blue-bar.png"));
    __android_log_print(ANDROID_LOG_DEBUG, "ArtrixHomeState", "2");
    mBw->SetSize(100, 50);
    __android_log_print(ANDROID_LOG_DEBUG, "ArtrixHomeState", "3");
    mHomeScreen->AddWidget(mBw);
    __android_log_print(ANDROID_LOG_DEBUG, "ArtrixHomeState", "4");
}

void ArtrixHomeState::Update(const StateMachine* sm, double gameTime){
    mBw->Print();
}
