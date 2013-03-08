/*
 * ImageWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once

#include "afx.h"

class ImageWidget: public Widget {
private:
	char*	m_pPath;
	GLint 	m_iTextureId;
protected:
	void onInitialize();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
public:
	ImageWidget();
	virtual ~ImageWidget();
};


