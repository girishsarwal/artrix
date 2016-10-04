#include "ButtonWidget.h"
using namespace AGK;
ButtonWidget::ButtonWidget()
    : CompositeWidget() {

}

ButtonWidget::~ButtonWidget(){
    //dtor
}

ButtonWidget::ButtonWidget(const Vector2& position, const Vector2& size, const string& text)
    : CompositeWidget(position, size) {
    mText = text;
}

ButtonWidget::ButtonWidget(const Vector2& position, const Vector2& size, const string& text, XMLNode* backgroundNode)
    : CompositeWidget(position, size) {
    mText = text;
}

ButtonWidget::ButtonWidget(XMLNode* node)
    : CompositeWidget (node) {
    mText = node->FirstChildElement("text")->GetText();

    /** background Widget **/
    WidgetFactory::CreateWidget(node->FirstChildElement("background")->FirstChild(), &mBackgroundWidget);

    mAction = node->FirstChildElement("action")->GetText();
    mParameters = node->FirstChildElement("action")->GetText();

}
void ButtonWidget::OnBeforeInitialize() {

}
void ButtonWidget::OnInitialize() {
    SetText(mText);
    SetAction(mAction, mParameters);

    mBackgroundWidget->Initialize();

    AddWidget(mBackgroundWidget);
}
void ButtonWidget::SetText(const string& text) {
    mText = text;
    OnSetText();
}
const string& ButtonWidget::GetText() const {
    return mText;
}


void ButtonWidget::SetBackground(ImageWidget* widget) {
    mBackgroundWidget = widget;
    OnSetBackground();
}
ImageWidget* ButtonWidget::GetBackground() const {
    return reinterpret_cast<ImageWidget*>(mBackgroundWidget);
}
void ButtonWidget::SetAction(const string& action, const string& parameters) {
    mAction = action;
    mParameters = parameters;
}

const string& ButtonWidget::GetAction() const {
    return mAction;
}
void ButtonWidget::OnSetVisible() {
    mBackgroundWidget->SetIsVisible(mIsVisible);
}

void ButtonWidget::OnSetPosition() {

}

void ButtonWidget::OnSetSize() {

}
void ButtonWidget::OnSetAction() {

}
void ButtonWidget::OnSetText() { }
void ButtonWidget::OnSetBackground() { }

