#include "widget.h"
Widget::Widget() {
    mPosition.Set(0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    SetPivot(0.5f, 0.5f);
    SetVisible(true);
    SetDefaultName();
}

Widget::Widget(const Vector2& position, const Vector2& size) {
    mPosition = position;
    mSize = size;
    SetPivot(0.5f, 0.5f);
    SetVisible(true);
    SetDefaultName();
}

Widget::~Widget() {

}
bool Widget::GetVisible() {
    return mIsVisible;
}
void Widget::SetVisible(bool isVisible){
    mIsVisible = isVisible;
}
Vector2& Widget::GetSize() {
    return mSize;
}
void Widget::SetSize(const Vector2& size) {
    SetSize(size.x, size.y);
}
void Widget::SetSize(float width, float height) {
    mSize.Set(width, height);
}
Vector2& Widget::GetPosition() {
    return mPosition;
}
void Widget::SetPosition(const Vector2& position) {
    SetPosition(position.x, position.y);
}
void Widget::SetPosition(float x, float y) {
    mPosition.Set(x, y);
}
Vector2& Widget::GetPivot() {
    return mPivot;
}
void Widget::SetPivot(const Vector2& pivot) {
    SetPivot(pivot.x, pivot.y);
}
void Widget::SetPivot(float pivotX, float pivotY) {
    mPivot.Set(pivotX, pivotY);
}
void Widget::SetDefaultName(){
    string defaultName = string("Widget ");
    defaultName += (++nextId);
    SetName(defaultName);
}
string Widget::GetName(){
    return mName;
}

void Widget::SetName(string& name){
    mName = name;
}

string Widget::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Widget::Print() {
    __android_log_print(ANDROID_LOG_VERBOSE, "Widget", "%s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Widget& widget) {
    stream << "{ name: " << widget.mName.c_str() << ", "
            << "position: " << widget.mPosition.dump() << ", "
            << "pivot: " << widget.mPivot.dump() << ", "
            << "size: " << widget.mSize.dump() << " }";
    return stream;
}

int Widget::nextId = 0;


