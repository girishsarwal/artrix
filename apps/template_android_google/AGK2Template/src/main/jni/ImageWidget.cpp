#include "ImageWidget.h"

ImageWidget::ImageWidget() {

}

ImageWidget::~ImageWidget() {
    //dtor
}
ImageWidget::ImageWidget(const Vector2& position, const Vector2& size)
    : LeafWidget(position, size) {

}


ImageWidget::ImageWidget(XMLNode* node)
    : LeafWidget (node) {
    mSource = node->ToElement()->Attribute("src");
}

string ImageWidget::GetSource() { return mSource; }
void ImageWidget::SetSource(const string& file) {
    mSource = file;

    mSourceImageId = agk::LoadImage(file.c_str());
    mSourceSpriteId = agk::CreateSprite(mSourceImageId);

    OnSetSource();
    ALOGD("ButtonWidget::SetBackground", "background regenerated ImageId=%d, SpriteId=%d", mSourceImageId, mSourceSpriteId);
}

void ImageWidget::OnBeforeInitialize() {
    SetSource(mSource);
}

void ImageWidget::OnSetSource() {
}

void ImageWidget::OnSetVisible() {
    agk::SetSpriteVisible(mSourceSpriteId, mIsVisible);
}
void ImageWidget::OnSetPosition() {
    agk::SetSpritePosition(mSourceSpriteId, mPosition.x, mPosition.y);
}
void ImageWidget::OnSetSize() {
    agk::SetSpriteSize(mSourceSpriteId, mSize.x, mSize.y);
}


