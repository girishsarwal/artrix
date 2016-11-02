#include "TextWidget.h"

TextWidget::TextWidget() {
    //ctor
}

TextWidget::~TextWidget() {
    //dtor
}
TextWidget::TextWidget(const Vector2& position, const Vector2& size, const string& text)
    : LeafWidget(position, size) {
    mText = text;
}

TextWidget::TextWidget(XMLNode* node):
    LeafWidget(node) {
    /** build the properties **/
    mText = node->ToElement()->FirstChildElement("value")->FirstChild()->Value();
}

const string& TextWidget::GetText() const { return mText; }
void TextWidget::SetText(const string& text) {
    mText = text;
    OnSetText();
}
float TextWidget::GetTextSize() const { return mTextSize; }
void TextWidget::SetTextSize(float textSize) {
    mTextSize= textSize;
    OnSetTextSize();
}

void TextWidget::OnBeforeInitialize() { }

void TextWidget::OnSetVisible() { }
void TextWidget::OnSetPosition() { }
void TextWidget::OnSetSize() { }
void TextWidget::OnSetText() { }
void TextWidget::OnSetTextSize() { }

