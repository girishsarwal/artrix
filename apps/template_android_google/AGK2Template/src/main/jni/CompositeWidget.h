#ifndef COMPOSITEWIDGET_H
#define COMPOSITEWIDGET_H

#include "widget.h"
#include <vector>
using namespace std;

class CompositeWidget : public Widget
{
    public:
        CompositeWidget();
        CompositeWidget(const Vector2&, const Vector2&);
        virtual ~CompositeWidget();
        void AddWidget();
        void RemoveWidget(std::string&);
        Widget* GetWidget(std::string&);
        virtual void Update();
    protected:
    private:
        vector<Widget*> mChildren;
};

#endif // COMPOSITEWIDGET_H
