#ifndef SCREEN_H
#define SCREEN_H
#include <vector>
#include "widget.h"
#include "utils.h"
#include "KeyManageable.h"
using namespace std;
class Screen
	: public KeyManageable
{
    public:

        Screen();
        virtual ~Screen();
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
        bool mIsVisible;
        vector<Widget*> mWidgets;
};

#endif // SCREEN_H
