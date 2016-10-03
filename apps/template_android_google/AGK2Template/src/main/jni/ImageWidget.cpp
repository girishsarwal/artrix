#include "ImageWidget.h"

ImageWidget::ImageWidget() {
    //ctor
}

ImageWidget::~ImageWidget() {
    //dtor
}
ImageWidget::ImageWidget(const Vector2& position, const Vector2& size)
    : LeafWidget(position, size)
{

}


ImageWidget::ImageWidget(XMLNode* node)
    : LeafWidget (node) {
    mBackgroundPath = node->ToElement()->Attribute("src");
}

string ImageWidget::GetBackground() { return mBackgroundPath; }
void ImageWidget::SetBackground(const string& file) {
    mBackgroundPath = file;

    mBackgroundImageId = agk::LoadImage(file.c_str());
    mBackgroundSpriteId = agk::CreateSprite(mBackgroundImageId);

    OnSetBackground();
    __android_log_print(ANDROID_LOG_DEBUG, "ButtonWidget::SetBackground", "background regenerated ImageId=%d, SpriteId=%d", mBackgroundImageId, mBackgroundSpriteId);
}

void ImageWidget::OnBeforeInitialize() {
    SetBackground(mBackgroundPath); /** this widget expects background to be available for initialization **/
}
void ImageWidget::OnInitialize() {

}

void ImageWidget::OnSetVisible() {
    agk::SetSpriteVisible(mBackgroundSpriteId, mIsVisible);
}
void ImageWidget::OnSetPosition() {
    agk::SetSpritePosition(mBackgroundSpriteId, mPosition.x, mPosition.y);
}

void ImageWidget::OnSetSize() {
    agk::SetSpriteSize(mBackgroundSpriteId, mSize.x, mSize.y);
}
void ImageWidget::OnSetBackground() {
}


