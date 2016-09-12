#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include "LeafWidget.h"
using namespace std;

class ButtonWidget : public LeafWidget
{
    public:
        ButtonWidget();
        ButtonWidget(Vector2& position, Vector2& dimension, string& text);
        ButtonWidget(Vector2& position, Vector2& dimension, string& text, string& background);
        virtual ~ButtonWidget();

    protected:
    private:
        string mText;
        int mBackgroundImageId;
        int mBackgroundSpriteId;
        int mBackgroundSpriteLayer;
};

#endif // BUTTONWIDGET_H
