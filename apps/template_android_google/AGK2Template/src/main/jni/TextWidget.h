#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <LeafWidget.h>


class TextWidget : public LeafWidget
{
    public:
        /** constructors */
        TextWidget();
        TextWidget(const Vector2& position, const Vector2& size, const string& text);
        TextWidget(XMLNode*);
        virtual ~TextWidget();

        /** properties **/
        const string& GetText() const;
        void SetText(const string&);
        float GetTextSize() const;
        void SetTextSize(float);
    protected:
        /** lifecycle hooks **/
        virtual void OnBeforeInitialize();

        /** property change hooks **/
        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();
        virtual void OnSetText();
        virtual void OnSetTextSize();
    private:
        string mText;
        float mTextSize;
};

#endif // TEXTWIDGET_H
