#include "screen.h"

Screen::Screen(){
    //ctor
}

Screen::~Screen(){
    //dtor
}

void Screen::AddWidget(Widget* widget){
    mWidgets.push_back(widget);
}
