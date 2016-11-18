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
class ImageWidget:
		public UIWidget {
private:

protected:
	uint 	m_iTextureId;
	std::string	m_pPath;
	virtual void CreateGeometry();
public:

	ImageWidget();
	ImageWidget(tinyxml2::XMLNode*);
	~ImageWidget();

	void OnInitialize();
	void OnAfterInitialize();
	bool ValidateAttributes();
	void OnRender(double frameTime);


};
#endif

