#include <android/log.h>
#include "ButtonWidget.h"
#include "agk.h"
using namespace AGK;
ButtonWidget::ButtonWidget()
    : LeafWidget(){

}

ButtonWidget::~ButtonWidget(){
    //dtor
}

ButtonWidget::ButtonWidget(const Vector2& position, const Vector2& size, const string& text)
    : LeafWidget(position, size)
{
    SetText(text);
}


ButtonWidget::ButtonWidget(XMLNode* node)
    : LeafWidget (node) {
    SetBackground(node->FirstChildElement("background")->GetText());
    SetText(node->FirstChildElement("text")->GetText());
    SetAction(node->FirstChildElement("action")->GetText(),node->FirstChildElement("action")->GetText());
}

ButtonWidget::ButtonWidget(const Vector2& position, const Vector2& size, const string& text, const string& background)
    : LeafWidget(position, size)
{
    SetText(text);
    SetBackground(background);
    __android_log_print(ANDROID_LOG_DEBUG, "ButtonWidget", "ImageId=%d, SpriteId=%d", mBackgroundImageId, mBackgroundSpriteId);
}
void ButtonWidget::SetText(const string& text) {
    mText = text;
    OnSetText();
}
const string& ButtonWidget::GetText() const {
    return mText;
}


void ButtonWidget::SetBackground(const string& file) {
    mBackgroundPath = file;

    mBackgroundImageId = agk::LoadImage(file.c_str());
    mBackgroundSpriteId = agk::CreateSprite(mBackgroundImageId);

    OnSetBackground();
}
const string& ButtonWidget::GetBackground() const {
    return mBackgroundPath;
}
void ButtonWidget::SetAction(const string& action, const string& parameters) {
    mAction = action;
    mParameters = parameters;
}

const string& ButtonWidget::GetAction() const {
    return mAction;
}
void ButtonWidget::OnSetVisible() {
    agk::SetSpriteVisible(mBackgroundSpriteId, mIsVisible);
}

void ButtonWidget::OnSetPosition() {
    agk::SetSpritePosition(mBackgroundSpriteId, mPosition.x, mPosition.y);
}

void ButtonWidget::OnSetSize() {
    agk::SetSpriteSize(mBackgroundSpriteId, mSize.x, mSize.y);
}
void ButtonWidget::OnSetAction() {

}
void ButtonWidget::OnSetText() { }
void ButtonWidget::OnSetBackground() { }
