#include "widget.h"
#include <android/log.h>
Widget::Widget()
{
    mPosition.Set(0.0f, 0.0f);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    mAnchor.Set(0.5f, 0.5f);
    SetVisible(true);

}

Widget::Widget(const Vector2& position, const Vector2& size)
{
    mPosition = position;
    mSize = size;
    mAnchor.Set(0.5f, 0.5f);
    SetVisible(true);
}

Widget::~Widget() {
    //dtor
}
bool Widget::GetVisible()
{
    return mIsVisible;
}
void Widget::SetVisible(bool isVisible)
{
    mIsVisible = isVisible;
}

void Widget::debug(){
    __android_log_print(ANDROID_LOG_VERBOSE, "Widget", "mName=%s, mPosition={%f, %f}, mAnchor={%f, %f}, mSize={%f, %f}, mIsVisible=%d",
            mName.c_str(), mPosition.x, mPosition.y, mAnchor.x, mAnchor.y, mSize.x, mSize.y, mIsVisible);
}
