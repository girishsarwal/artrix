#ifndef COMPOSITEWIDGET_H
#define COMPOSITEWIDGET_H
#include <vector>
#include <tinyxml2.h>
#include "widget.h"
using namespace std;
using namespace tinyxml2;

class CompositeWidget : public Widget
{
    public:
        CompositeWidget();
        CompositeWidget(const Vector2&, const Vector2&);
        CompositeWidget(XMLNode*);
        virtual ~CompositeWidget();
        void AddWidget();
        void RemoveWidget(string&);
        Widget* GetWidget(string&);
        virtual void Update();
        string dump() const;
        void Print();
        friend ostream& operator<<(ostream&, const CompositeWidget&);
    protected:
    private:
        vector<Widget*> mChildren;
};

#endif // COMPOSITEWIDGET_H
