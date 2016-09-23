#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H
#include "LeafWidget.h"
#include <vector>
using namespace std;

class ButtonWidget : public LeafWidget
{
    public:
        ButtonWidget();
        ButtonWidget(const Vector2& position, const Vector2& dimension, const string& text);
        ButtonWidget(const Vector2& position, const Vector2& dimension, const string& text, const string& background);
        ButtonWidget(XMLNode*);
        virtual ~ButtonWidget();

        void SetText(const string&);
        const string& GetText() const;
        void SetBackground(const string&);
        const string& GetBackground() const;
        void SetAction(const string&, const string&);
        const string& GetAction() const;

    protected:
        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();
        virtual void OnSetText();
        virtual void OnSetBackground();
        virtual void OnSetAction();
    private:
        string mText;
        string mBackgroundPath;
        string mAction;
        string mParameters;

        int mBackgroundImageId;
        int mBackgroundSpriteId;
        int mBackgroundSpriteLayer;
};

#endif // BUTTONWIDGET_H
