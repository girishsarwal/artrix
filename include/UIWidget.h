/*
 * UIWidget.h.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#ifndef UIWIDGET_H
#define UIWIDGET_H
#include "afx.h"
#include "Widget.h"
#include "Program.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

class UIWidget :
		public Widget {
private:

protected:	
	Program*	m_pShadingProgram;
	gtfx::TransformComponent* mTransformComponent;
	gtfx::RenderComponent* mRenderComponent;

public:
	UIWidget();
	UIWidget(tinyxml2::XMLNode*);
	virtual ~UIWidget();
	virtual void OnInitialize();
	virtual void OnUpdate(double gameTime);
};
#endif


