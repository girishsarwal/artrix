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
	std::string	m_pPath;
	
	unsigned long long m_fBackground;
	
	uint 	m_iTextureId;
	
protected:
	void onInitialize();
	void onUpdate(double frameTime);
	void onRender(double frameTime);
public:
	ImageWidget();
	ImageWidget(AttributeSet& attrs);
	virtual ~ImageWidget();
};


