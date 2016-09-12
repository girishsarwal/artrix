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
        virtual ~Widget();
        virtual void Update() = 0;
    protected:
    private:
        string mName;
        Vector2 mPosition;
        Vector2 mAnchor;
        Vector2 mSize;
};

#endif // WIDGET_H
