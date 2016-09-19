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
    mBackgroundImageId = agk::LoadImage(background.c_str());
    mBackgroundSpriteId = agk::CreateSprite(mBackgroundImageId);

    __android_log_print(ANDROID_LOG_DEBUG, "ButtonWidget", "ImageId=%d, SpriteId=%d", mBackgroundImageId, mBackgroundSpriteId);
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
