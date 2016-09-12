#ifndef SCREEN_H
#define SCREEN_H
#include "widget.h"
#include <vector>
using namespace std;
class Screen
{
    public:
        Screen();
        virtual ~Screen();
        void AddWidget(Widget*);

    protected:
    private:
        vector<Widget*> mWidgets;
};

#endif // SCREEN_H
