#include "ButtonWidget.h"
#include "agk.h"
using namespace AGK;
ButtonWidget::ButtonWidget()
    : LeafWidget()
{

}

ButtonWidget::~ButtonWidget()
{
    //dtor
}
ButtonWidget::ButtonWidget(Vector2& position, Vector2& size, string& text)
    : LeafWidget(position, size)
{
    mText = text;
}

ButtonWidget::ButtonWidget(Vector2& position, Vector2& size, string& text, string& background)
    : LeafWidget(position, size)
{
    mText = text;
    mBackgroundImageId = agk::LoadImage(background.c_str());
    mBackgroundSpriteId = agk::CreateSprite(mBackgroundImageId);
    agk::SetSpriteVisible(mBackgroundSpriteId, mIsVisible);
}

