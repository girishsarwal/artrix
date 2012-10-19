/*
 * ImageWidget.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once

#include "artrix-includes.h"

class ImageWidget: public Widget {
protected:
	void onUpdate();
	void onRender();
public:
	ImageWidget();
	virtual ~ImageWidget();
};


