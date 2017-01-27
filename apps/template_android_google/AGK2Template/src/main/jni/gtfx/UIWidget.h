/*
 * UIWidget.h.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#ifndef UIWIDGET_H
#define UIWIDGET_H
#include "GameObject.h"
#include "afx.h"
namespace gtfx {
class Program;
class TransformComponent;
class RenderComponent;
class UIWidget :
		public gtfx::GameObject {
private:

protected:	
	Program* mShadingProgram;
	TransformComponent* mTransformComponent;
	RenderComponent* mRenderComponent;

public:
	UIWidget();
	UIWidget(tinyxml2::XMLNode*);
	virtual ~UIWidget();
	virtual void OnInitialize();
	virtual void OnUpdate(double gameTime);
};
}
#endif


