#ifndef SCREEN_H
#define SCREEN_H
#include "widget.h"
#include <vector>
using namespace std;
class Screen
{
    public:

        Screen();
        Screen(const string&);
        virtual ~Screen();
        const string& GetName() const;
        bool GetIsVisible() const;
        void SetIsVisible(bool);
        const vector<Widget*>& GetWidgets() const;
        void AddWidget(Widget*);
        bool operator==(const Screen&) const;
        bool operator!=(const Screen&) const;
        void Update();
        string dump() const;
        virtual void Print();
        friend ostream& operator<<(ostream&, const Screen&);

    protected:
    private:
        string mName;
        bool mIsVisible;
        vector<Widget*> mWidgets;
};

#endif // SCREEN_H
