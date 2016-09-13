#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include "LeafWidget.h"
using namespace std;

class ButtonWidget : public LeafWidget
{
    public:
        ButtonWidget();
        ButtonWidget(const Vector2& position, const Vector2& dimension, const string& text);
        ButtonWidget(const Vector2& position, const Vector2& dimension, const string& text, const string& background);
        virtual ~ButtonWidget();
    protected:
    private:
        string mText;
        int mBackgroundImageId;
        int mBackgroundSpriteId;
        int mBackgroundSpriteLayer;
};

#endif // BUTTONWIDGET_H
