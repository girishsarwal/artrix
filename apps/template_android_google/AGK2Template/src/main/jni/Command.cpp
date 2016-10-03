#include "Command.h"

Command::Command() {
    //ctor
}
Command::Command(const string& name) {
    mName = name;
    mIsAvailable = true;
}
Command::Command(const string& name, bool isAvailable) {
    mName = name;
    mIsAvailable = isAvailable;
}
Command::Command(XMLNode* node) {
    mName = node->FirstChild()->ToElement()->Attribute("name");
    mIsAvailable = node->FirstChild()->ToElement()->Attribute("available") == "true";
}

Command::~Command() {
    //dtor
}

bool Command::GetIsAvailable() { return mIsAvailable; }
void Command::SetIsAvailable(bool isAvailable) {
    mIsAvailable = isAvailable;
}
const string& Command::GetName() const { return mName; }
void Command::SetName(const string& name) {
    mName = name;
}


void Command::PreExecute() {
    OnPreExecute();
    ALOGD("Command::Execute", "post execute completed");
}
void Command::Execute() {
    PreExecute();
    if(!mIsAvailable) {
        ALOGD("Command::Execute", "command is not available");
        return;
    }
    OnExecute();
    PostExecute();
}
void Command::PostExecute() {
    OnPostExecute();
    ALOGD("Command::Execute", "post execute completed");
}

void Command::OnSetAvailable() { }
void Command::OnPreExecute() { ALOGD("Command::OnPreExecute", "base was called"); }
void Command::OnPostExecute() {  ALOGD("Command::OnPostExecute", "base was called"); }
