#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H
#include "LeafWidget.h"
#include "WidgetAttribute.h"
#include <vector>
using namespace std;

class ButtonWidget : public LeafWidget
{
    public:
        ButtonWidget();
        ButtonWidget(const Vector2& position, const Vector2& dimension, const string& text);
        ButtonWidget(const Vector2& position, const Vector2& dimension, const string& text, const string& background);
        ButtonWidget(vector<WidgetAttribute*> attributes);
        void SetText(const string&);
        virtual ~ButtonWidget();
    protected:
        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();
    private:
        string mText;
        int mBackgroundImageId;
        int mBackgroundSpriteId;
        int mBackgroundSpriteLayer;
};

#endif // BUTTONWIDGET_H
