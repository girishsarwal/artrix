#include "widget.h"
Widget::Widget() {
    mPosition.Set(0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    mPivot.Set(0.5f, 0.5f);
    mIsVisible = true;
    SetDefaultName();
}

Widget::Widget(const Vector2& position, const Vector2& size) {
    mPosition.Set(0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    mPivot.Set(0.5f, 0.5f);
    mIsVisible = true;
    SetDefaultName();
}

Widget::Widget(XMLNode* node) {
    mPosition = Vector2(node->FirstChildElement("position")->FirstChild());
    mSize = Vector2(node->FirstChildElement("size")->FirstChild());
    mIsVisible = true;
    mPivot = Vector2(node->FirstChildElement("anchor")->FirstChild());
}

Widget::~Widget() {

}

bool Widget::GetIsInitialized() const {
    return mIsInitialized;
}
void Widget::Initialize() {
    OnBeforeInitialize();

    SetPosition(mPosition);     /** I know this sounds stupid to do but C++ makes objects like an onion, inside out and we need to call some virt func during creation **/
    SetSize(mSize);
    SetPivot(mPivot);
    SetIsVisible(mIsVisible);

    OnInitialize();             /** we let the dervied class function execute first **/
    mIsInitialized = true;

    OnAfterInitialize();
}


bool Widget::GetIsVisible() const {
    return mIsVisible;
}
void Widget::SetIsVisible(bool isVisible){
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
void Widget::BeforeInitialize() {
    OnBeforeInitialize();
}
void Widget::AfterInitialize() {
    OnAfterInitialize();
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

void Widget::SetName(const string& name){
    mName = name;
}

void Widget::Update() {
    OnUpdate();
}
void Widget::Draw() {
    OnDraw();
}
void Widget::OnBeforeInitialize() { ALOGW("Widget::OnBeforeInitialize", "base was called"); }
void Widget::OnInitialize() { ALOGW("Widget::OnBeforeInitialize", "base was called"); }
void Widget::OnAfterInitialize() { ALOGW("Widget::OnAfterInitialize", "base was called"); }
void Widget::OnSetVisible() { ALOGW("Widget::OnSetVisible", "base was called"); }
void Widget::OnSetPosition() { ALOGW("Widget::OnSetPosition", "base was called");}
void Widget::OnSetSize() { ALOGW("Widget::OnSetSize", "base was called");}
void Widget::OnUpdate() { }
void Widget::OnDraw() { }

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

