#ifndef WIDGET_H
#define WIDGET_H
#include <android/log.h>
#include <string>
#include <sstream>

#include "agk.h"
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
        Vector2& GetSize();
        void SetSize(const Vector2&);
        void SetSize(float, float);
        Vector2& GetPosition();
        void SetPosition(const Vector2&);
        void SetPosition(float, float);
        Vector2& GetPivot();
        void SetPivot(const Vector2&);
        void SetPivot(float, float);
        string dump() const;
        virtual void Print();
        friend ostream& operator<<(ostream& stream, const Widget& widget);

    protected:
        string mName;
        Vector2 mPosition;
        Vector2 mPivot;
        Vector2 mSize;
        bool mIsVisible;

        string _str;

};

#endif // WIDGET_H
