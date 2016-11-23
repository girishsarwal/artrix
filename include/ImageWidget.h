/*
 * ImageWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */
#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H
#include "afx.h"
#include "UIWidget.h"
#include "TextureManager.h"
#include "ShadingProgramManager.h"
class ImageWidget:
		public UIWidget {
private:
	Texture* mTexture;
protected:
	std::string	mSource;

	void OnInitialize();
	void OnAfterInitialize();
	bool ValidateAttributes();
	void OnRender(double frameTime);

public:

	ImageWidget();
	ImageWidget(tinyxml2::XMLNode*);
	~ImageWidget();

	const std::string& GetSource() const;
	void SetSource(const std::string&);


};
#endif

