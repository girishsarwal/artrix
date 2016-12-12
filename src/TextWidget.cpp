/*
 * TextWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		Modified: girish
 */

#include "TextWidget.h"
namespace gtfx {

TextWidget::TextWidget() {

};

TextWidget::TextWidget(tinyxml2::XMLNode*) {

};

TextWidget::~TextWidget() {

};

const std::string& TextWidget::GetText() const {
	return mText;
};

void TextWidget::SetText(const std::string& text) {
	mText = text;
};

const std::string& TextWidget::GetFont() const {
	return mFont;
};
void TextWidget::SetFont(const std::string& font) {
	mFont = font;
};
float TextWidget::GetFontSize() {
	return mFontSize;
};
void TextWidget::SetFontSize(float fontSize) {
	mFontSize = fontSize;
};
bool TextWidget::GetFontBold() {
	return mFontBold;
};
void TextWidget::SetFontBold(bool fontBold) {
	mFontBold = fontBold;
};
unsigned long TextWidget::GetFontColor() {
	return mFontColor;
};
void TextWidget::SetFontColor(unsigned long fontColor) {
	mFontColor = fontColor;
};

/** property hooks **/
void TextWidget::OnSetText() {

};
void TextWidget::OnSetFont() {

};
void TextWidget::OnSetFontSize() {

};
void TextWidget::OnSetFontBold() {

};
void TextWidget::OnSetFontColor() {

};

bool TextWidget::ValidateAttributes() {
	return true;
};
void TextWidget::OnInitialize() {

};
void TextWidget::OnRender(double frameTime) {
	//	glColor4ub((m_fColor & 0x00FF0000) >> 0x10,
	//				(m_fColor & 0x0000FF00) >> 0x08,
	//				m_fColor & 0x000000FF,
	//				(m_fColor & 0xFF000000) >> 0x18);
	//	glTranslatef(m_vPosition.x, m_vPosition.y, 1);
	//	glEnable(GL_TEXTURE_2D);
	//	glPushMatrix();
	//	//FM->setActiveFont(m_pFont, m_pSize, m_bIsBold);
	//	//uint id = TM->getTexture(m_pFont);
	//	glBindTexture(GL_TEXTURE_2D, TM->getTexture(m_pFont));
	//	//glListBase(-32);
	//	glScalef(m_pSize/10.0, m_pSize/10.0, 1);
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//	glEnable(GL_BLEND);
	//	glCallLists(m_pText.length(), GL_BYTE, m_pText.c_str());
	//	glDisable(GL_BLEND);
	//	glPopMatrix();
	//	glDisable(GL_TEXTURE_2D);
};
}
