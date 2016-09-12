#ifndef LEAFWIDGET_H
#define LEAFWIDGET_H

#include "widget.h"


class LeafWidget : public Widget
{
    public:
        LeafWidget();
        LeafWidget(Vector2&, Vector2&);
        virtual ~LeafWidget();
        virtual void Update();
    protected:
    private:
};

#endif // LEAFWIDGET_H
