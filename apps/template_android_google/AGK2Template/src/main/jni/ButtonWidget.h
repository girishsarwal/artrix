#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H
/** TODO: fix these headers **/
#include "CompositeWidget.h"
#include "WidgetFactory.h"
#include "ImageWidget.h"
#include "utils.h"
#include "android/log.h"
#include <vector>
using namespace std;

class ButtonWidget : public CompositeWidget
{
    public:
        ButtonWidget();
        ButtonWidget(const Vector2&, const Vector2&, const string&);
        ButtonWidget(const Vector2&, const Vector2&, const string&, XMLNode*);
        ButtonWidget(XMLNode*);
        virtual ~ButtonWidget();

        void SetText(const string&);
        const string& GetText() const;
        void SetBackground(ImageWidget*);
        ImageWidget* GetBackground() const;
        void SetAction(const string&, const string&);
        const string& GetAction() const;

    protected:
        virtual void OnBeforeInitialize();
        virtual void OnInitialize();

        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();
        virtual void OnSetText();
        virtual void OnSetBackground();
        virtual void OnSetAction();
    private:
        string mText;
        string mAction;
        string mParameters;
        Widget* mBackgroundWidget;

};

#endif // BUTTONWIDGET_H
