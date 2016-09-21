#ifndef WIDGET_H
#define WIDGET_H
#include <stdio.h>
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

        bool GetVisible() const;
        void SetVisible(bool);
        const Vector2& GetSize() const;
        void SetSize(const Vector2&);
        void SetSize(float, float);
        const Vector2& GetPosition() const;
        void SetPosition(const Vector2&);
        void SetPosition(float, float);
        const Vector2& GetPivot() const;
        void SetPivot(const Vector2&);
        void SetPivot(float, float);
        const string& GetName() const;
        void SetName(string&);
        string dump() const;
        virtual void Print();
        friend ostream& operator<<(ostream& stream, const Widget& widget);

        bool operator==(const Widget& rhs) const;
        bool operator!=(const Widget& rhs) const;

    protected:
        string mName;
        Vector2 mPosition;
        Vector2 mPivot;
        Vector2 mSize;
        bool mIsVisible;

        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();

        string _str;
    private:
        static int nextId;
        void SetDefaultName();
};

#endif // WIDGET_H
