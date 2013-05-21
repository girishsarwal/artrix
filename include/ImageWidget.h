/*
 * ImageWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once

#include "afx.h"

class ImageWidget: public UIWidget {
private:
	uint 	m_iTextureId;
protected:
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
	virtual void onRender(double frameTime);
public:
	std::string	m_pPath;
		
	ImageWidget();
	virtual ~ImageWidget();
};


