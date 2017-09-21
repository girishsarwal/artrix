#include "screen.h"

Screen::Screen(){
    SetDefaultName(string("Screen"));
}

Screen::~Screen(){

}


void Screen::AddWidget(Widget* widget){
    mWidgets.push_back(widget);
}

const vector<Widget*>& Screen::GetWidgets() const {
    return mWidgets;
}
bool Screen::operator==(const Screen& rhs) const {
    return (this->mName == rhs.mName);
}
bool Screen::operator!=(const Screen& rhs) const {
    return !(*this == rhs);
}

string Screen::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Screen::Print() {
    ALOGD("Screen::Print", "%s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Screen& screen) {
    stream << "<screen name=\"" << screen.mName.c_str() << "\">\n"
        << "widgets: ";
    vector<Widget*>::const_iterator it = screen.GetWidgets().begin();
    while(it != screen.GetWidgets().end()) {
        stream << (*it)->dump();
        it++;
    }
    stream << "</screen>\n";

    return stream;
}

bool Screen::GetIsVisible() const {
    return mIsVisible;
}

void Screen::SetIsVisible(bool visible) {
    /** set all the wigets visible ***/
    std::vector<Widget*>::iterator it = mWidgets.begin();
    while (it != mWidgets.end()) {
        (*it)->SetIsVisible(visible);
        it++;
    }
    mIsVisible = visible;
}
void Screen::Update() {
    std::vector<Widget*>::iterator it = mWidgets.begin();
    while (it != mWidgets.end()) {
        if(! (*it)->GetIsInitialized()) {
            (*it)->Initialize();
        }
        (*it)->Update();
        (*it)->Draw();
        it++;
    }
}