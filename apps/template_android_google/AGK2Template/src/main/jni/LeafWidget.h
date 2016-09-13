#ifndef LEAFWIDGET_H
#define LEAFWIDGET_H

#include "widget.h"


class LeafWidget : public Widget
{
    public:
        LeafWidget();
        LeafWidget(const Vector2&, const Vector2&);
        virtual ~LeafWidget();
        virtual void Update();
    protected:
    private:
};

#endif // LEAFWIDGET_H
