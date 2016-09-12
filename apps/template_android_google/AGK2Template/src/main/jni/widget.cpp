#include "widget.h"

Widget::Widget()
{
    mPosition.Set(0, 0);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    mAnchor.Set(0.5, 0.5);

}

Widget::Widget(Vector2& position, Vector2& size)
{
    mPosition = position;
    mSize = size;
}

Widget::~Widget()
{
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
