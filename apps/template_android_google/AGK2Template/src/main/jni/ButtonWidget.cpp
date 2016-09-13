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
    agk::SetSpriteVisible(mBackgroundSpriteId, mIsVisible);
    __android_log_print(ANDROID_LOG_VERBOSE, "ButtonWidget", "ImageId=%d, SpriteId=%d", mBackgroundImageId, mBackgroundSpriteId);
}
