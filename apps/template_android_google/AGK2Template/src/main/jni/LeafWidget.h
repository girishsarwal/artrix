#ifndef LEAFWIDGET_H
#define LEAFWIDGET_H
#include <tinyxml2.h>
#include "widget.h"
using namespace tinyxml2;
class LeafWidget : public Widget
{
    public:
        LeafWidget();
        LeafWidget(const Vector2&, const Vector2&);
        LeafWidget(XMLNode*);
        virtual ~LeafWidget();
        virtual void Update();
    protected:
    private:
};

#endif // LEAFWIDGET_H
