#include "screen.h"

Screen::Screen(){
    //ctor
}

Screen::~Screen(){
    //dtor
}

Screen::Screen(const string& name) {
    mName = name;
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
    __android_log_print(ANDROID_LOG_DEBUG, "Screen", "%s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Screen& screen) {
/** TODO: Change to xml serialization **/
    stream << "{ name: " << screen.mName.c_str() << ", "
        << "widgets: ";

    vector<Widget*>::const_iterator it = screen.GetWidgets().begin();
    while(it != screen.GetWidgets().end()) {
        stream << "[" << (*it)->dump() << "]";
        it++;
    }
    stream << "}";

    return stream;
}

bool Screen::GetIsVisible() const {
    return mIsVisible;
}

void Screen::SetIsVisible(bool visible) {
    /** set all the wigets visible ***/
    std::vector<Widget*>::iterator it = mWidgets.begin();
    while (it != mWidgets.end()) {
        (*it)->SetVisible(visible);
        it++;
    }
    mIsVisible = visible;
}
void Screen::Update() {
    std::vector<Widget*>::iterator it = mWidgets.begin();
    while (it != mWidgets.end()) {
        (*it)->Update();
        it++;
    }
}
