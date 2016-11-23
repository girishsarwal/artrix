/*
 * UIWidget.h.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#ifndef UIWIDGET_H
#define UIWIDGET_H
#include "afx.h"
#include "Vector3.h"
#include "Widget.h"
#include "Renderable.h"
#include "Program.h"

class UIWidget :
		public Widget,
		public Renderable {
private:

protected:	
	Program*	m_pShadingProgram;
public:
	UIWidget();
	UIWidget(tinyxml2::XMLNode*);
	virtual ~UIWidget();
	virtual void OnInitialize();
	virtual void OnUpdate(double gameTime);
};
#endif


