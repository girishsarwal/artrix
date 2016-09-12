#include "widget.h"

Widget::Widget()
{
    mPosition.Set(0, 0);
    mSize.Set(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
    mAnchor.Set(DEFAULT_WIDGET_SIZE/2, DEFAULT_WIDGET_SIZE/2);

}

Widget::~Widget()
{
    //dtor
}
