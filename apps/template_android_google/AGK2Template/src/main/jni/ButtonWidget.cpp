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
    mText = text;
}



ButtonWidget::ButtonWidget(const Vector2& position, const Vector2& size, const string& text, const string& background)
    : LeafWidget(position, size)
{
    mText = text;
    mBackgroundPath = background;
}

ButtonWidget::ButtonWidget(XMLNode* node)
    : LeafWidget (node) {
    mText = node->FirstChildElement("text")->GetText();
    mBackgroundPath = node->FirstChildElement("background")->GetText();
    mAction = node->FirstChildElement("action")->GetText();
    mParameters = node->FirstChildElement("action")->GetText();

}
void ButtonWidget::OnBeforeInitialize() {
    SetBackground(mBackgroundPath);     /** this widget needs the background before position etc can be set because the position of the sprite depends on the size **/

}
void ButtonWidget::OnInitialize() {
    SetText(mText);
    SetAction(mAction, mParameters);
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
    __android_log_print(ANDROID_LOG_DEBUG, "ButtonWidget::SetBackground", "background regenerated ImageId=%d, SpriteId=%d", mBackgroundImageId, mBackgroundSpriteId);
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

