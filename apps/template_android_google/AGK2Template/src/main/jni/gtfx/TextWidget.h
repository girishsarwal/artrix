/*
 * TextWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: manmohan
 * 		modified: girish
 */

#pragma once
#include "afx.h"
#include "UIWidget.h"
namespace gtfx {
class TextWidget:
	public UIWidget {

protected:
	std::string	mText;
	std::string mFont;
	float mFontSize;
	bool mFontBold;
	unsigned long mFontColor;

	/** property hooks **/
	virtual void OnSetText();
	virtual void OnSetFont();
	virtual void OnSetFontSize();
	virtual void OnSetFontBold();
	virtual void OnSetFontColor();

	virtual void OnInitialize();
	virtual void OnRender(double frameTime);

public:
	TextWidget();
	TextWidget(tinyxml2::XMLNode*);
	virtual ~TextWidget();

	const std::string& GetText() const;
	void SetText(const std::string&);
	const std::string& GetFont() const;
	void SetFont(const std::string&);
	float GetFontSize();
	void SetFontSize(float);
	bool GetFontBold();
	void SetFontBold(bool);
	unsigned long GetFontColor();
	void SetFontColor(unsigned long);


	bool ValidateAttributes();
};
}

