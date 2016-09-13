#ifndef WIDGET_H
#define WIDGET_H
#include <string>

#include "Vector2.h"
#define DEFAULT_WIDGET_SIZE 100
using namespace std;

class Widget
{
    public:
        Widget();
        Widget(const Vector2&, const Vector2&);

        virtual ~Widget();
        virtual void Update() = 0;

        bool GetVisible();
        void SetVisible(bool);

        void debug();

    protected:
        string mName;
        Vector2 mPosition;
        Vector2 mAnchor;
        Vector2 mSize;
        bool mIsVisible;
    private:

};

#endif // WIDGET_H
