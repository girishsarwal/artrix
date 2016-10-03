#include "Command.h"

Command::Command() {
    //ctor
}

Command::~Command() {
    //dtor
}

bool Command::GetIsAvailable() { return mIsAvailable; }
void Command::SetIsAvailable(bool isAvailable) {
    mIsAvailable = isAvailable;
}


void Command::PreExecute() { }
void Command::PostExecute() { }

void Command::OnSetAvailable() { }
void Command::OnPreExecute() { }
void Command::OnExecute() { }
void Command::OnPostExecute() { }
