#include "widget.h"
#include <android/log.h>
Widget::Widget() {
    mPosition.Set(0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    SetPivot(0.5f, 0.5f);
    SetVisible(true);

}

Widget::Widget(const Vector2& position, const Vector2& size) {
    mPosition = position;
    mSize = size;
    SetPivot(0.5f, 0.5f);
    SetVisible(true);
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

void Widget::debug() {
    __android_log_print(ANDROID_LOG_VERBOSE, "Widget", "mName=%s, mPosition={%f, %f}, mAnchor={%f, %f}, mSize={%f, %f}, mIsVisible=%d",
            mName.c_str(), mPosition.x, mPosition.y, mPivot.x, mPivot.y, mSize.x, mSize.y, mIsVisible);
}
