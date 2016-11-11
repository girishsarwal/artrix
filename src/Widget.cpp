#include "Widget.h"

Widget::Widget() {
    mPosition.Set(0.0f, 0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0.0f);
    mPivot.Set(0.5f, 0.5f, 0.5f);
    mIsVisible = true;
    SetDefaultName(string("Widget"));
}

Widget::Widget(const Vector3& position, const Vector3& size) {
    mPosition.Set(0.0f, 0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0);
    mPivot.Set(0.5f, 0.5f, 0.5f);
    mIsVisible = true;
    SetDefaultName(string("Widget"));
}

Widget::Widget(tinyxml2::XMLNode* node) {
    mPosition = Vector3(node->FirstChildElement("position")->FirstChild());
    mSize = Vector3(node->FirstChildElement("size")->FirstChild());
    mIsVisible = true;
    mPivot = Vector3(node->FirstChildElement("anchor")->FirstChild());
    SetDefaultName(string("Widget"));
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
const Vector3& Widget::GetSize() const {
    return mSize;
}
void Widget::SetSize(const Vector3& size) {
    SetSize(size.x, size.y, size.z);
}
void Widget::SetSize(float width, float height, float depth) {
    mSize.Set(width, height, depth);
    OnSetSize();
}
const Vector3& Widget::GetPosition() const {
    return mPosition;
}
void Widget::SetPosition(const Vector3& position) {
    SetPosition(position.x, position.y, position.z);
}
void Widget::SetPosition(float x, float y, float z) {
    mPosition.Set(x, y, z);
    OnSetPosition();
}
void Widget::BeforeInitialize() {
    OnBeforeInitialize();
}
void Widget::AfterInitialize() {
    OnAfterInitialize();
}
const Vector3& Widget::GetPivot() const {
    return mPivot;
}
void Widget::SetPivot(const Vector3& pivot) {
    SetPivot(pivot.x, pivot.y, pivot.z);
}
void Widget::SetPivot(float pivotX, float pivotY, float pivotZ) {
    mPivot.Set(pivotX, pivotY, pivotZ);
}


void Widget::Update(double gameTime) {
    OnUpdate(gameTime);
}
void Widget::Draw(double gameTime) {
    OnDraw(gameTime);
}
void Widget::OnBeforeInitialize() { ALOGW("Widget::OnBeforeInitialize", "base was called"); }
void Widget::OnInitialize() { ALOGW("Widget::OnBeforeInitialize", "base was called"); }
void Widget::OnAfterInitialize() { ALOGW("Widget::OnAfterInitialize", "base was called"); }
void Widget::OnSetVisible() { ALOGW("Widget::OnSetVisible", "base was called"); }
void Widget::OnSetPosition() { ALOGW("Widget::OnSetPosition", "base was called");}
void Widget::OnSetSize() { ALOGW("Widget::OnSetSize", "base was called");}
void Widget::OnUpdate(double gameTime) { }
void Widget::OnDraw(double gameTime) { }

string Widget::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Widget::Print() {
    ALOGI("Widget - %s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Widget& widget) {
    stream << "<widget type=\"undefined\" name =\"" << widget.mName.c_str() << "\">\n"
            << "\t<position>" << widget.mPosition.dump() << "</position>\n"
            << "\t<pivot>" << widget.mPivot.dump() << "</pivot>\n"
            << "\t<size>" << widget.mSize.dump() << "</size>\n"
            << "</widget>";

    return stream;
}



bool Widget::operator==(const Widget& rhs) const {
    return (this->mName == rhs.mName);
};
bool Widget::operator!=(const Widget& rhs) const {
    return !(*this == rhs);
};
