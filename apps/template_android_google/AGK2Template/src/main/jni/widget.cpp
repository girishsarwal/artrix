#include "widget.h"
Widget::Widget() {
    SetPosition(0.0f, 0.0f);
    SetSize(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    SetPivot(0.5f, 0.5f);
    SetVisible(true);
    SetDefaultName();
}

Widget::Widget(const Vector2& position, const Vector2& size) {
    SetPosition(position);
    SetSize(size);
    SetPivot(0.5f, 0.5f);
    SetVisible(true);
    SetDefaultName();
}

Widget::Widget(XMLNode* node) {
    SetPosition(Vector2(node->FirstChildElement("position")->FirstChild()));
    SetSize(Vector2(node->FirstChildElement("size")->FirstChild()));
    SetPivot(Vector2(node->FirstChildElement("anchor")->FirstChild()));
}

Widget::~Widget() {

}
bool Widget::GetVisible() const {
    return mIsVisible;
}
void Widget::SetVisible(bool isVisible){
    mIsVisible = isVisible;
    OnSetVisible();
}
const Vector2& Widget::GetSize() const {
    return mSize;
}
void Widget::SetSize(const Vector2& size) {
    SetSize(size.x, size.y);
}
void Widget::SetSize(float width, float height) {
    mSize.Set(width, height);
    OnSetSize();
}
const Vector2& Widget::GetPosition() const {
    return mPosition;
}
void Widget::SetPosition(const Vector2& position) {
    SetPosition(position.x, position.y);
}
void Widget::SetPosition(float x, float y) {
    mPosition.Set(x, y);
    OnSetPosition();
}
const Vector2& Widget::GetPivot() const {
    return mPivot;
}
void Widget::SetPivot(const Vector2& pivot) {
    SetPivot(pivot.x, pivot.y);
}
void Widget::SetPivot(float pivotX, float pivotY) {
    mPivot.Set(pivotX, pivotY);
}
void Widget::SetDefaultName(){
    char widgetName[10];
    sprintf(widgetName, "Widget%d", (++nextId));
    string defaultName = string(widgetName);
    SetName(defaultName);
}
const string& Widget::GetName() const{
    return mName;
}

void Widget::SetName(string& name){
    mName = name;
}

void Widget::Update() {
    __android_log_print(ANDROID_LOG_DEBUG, "Widget::Update", "position is %s, %f, %f", mName.c_str(), mPosition.x, mPosition.y);
    OnUpdate();
}

void Widget::OnSetVisible() {}
void Widget::OnSetPosition() {}
void Widget::OnSetSize() {}
void Widget::OnUpdate() {}

string Widget::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Widget::Print() {
    __android_log_print(ANDROID_LOG_DEBUG, "Widget", "%s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Widget& widget) {
    stream << "<widget type=\"undefined\" name =\"" << widget.mName.c_str() << "\">\n"
            << "\t<position>" << widget.mPosition.dump() << "</position>\n"
            << "\t<pivot>" << widget.mPivot.dump() << "</pivot>\n"
            << "\t<size>" << widget.mSize.dump() << "</size>\n"
            << "</widget>";

    return stream;
}

int Widget::nextId = 0;


bool Widget::operator==(const Widget& rhs) const {
    return (this->mName == rhs.mName);
};
bool Widget::operator!=(const Widget& rhs) const {
    return !(*this == rhs);
};

