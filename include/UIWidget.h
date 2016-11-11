/*
 * UIWidget.h.h
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#pragma once
#include "afx.h"
#include "Vector3.h"
#include "Widget.h"
#include "Renderable.h"
#include "Program.h"

class UIWidget : public Widget, Renderable {

protected:	

	virtual void beforeInitialize();
	virtual void onInitialize() = 0;
	virtual void afterInitialize();
	virtual void beforeRender(double frameTime);
	virtual void onRender(double frameTime) = 0;
	virtual void afterRender(double frameTime);
	virtual void beforeUpdate(double frameTime);
	virtual void onUpdate(double frameTime) = 0;
	virtual void afterUpdate(double frameTime);
	
	GLint		m_iSizeVertex;
	GLint		m_iSizeVertices;
	GLint		m_iSizeIndices;
	
	GLint 		m_iNumVertices;
	GLint		m_iNumTriangles;
	
	GLvoid*		m_pVertices;
	GLvoid*		m_pIndices;
	
	GLuint		m_iVertexBuffer;
	GLuint		m_iIndexBuffer;
	
	Program*	m_pShadingProgram;
public:
	Vector3 m_vPosition;
	Vector3 m_vSize;
	Vector3 m_vHalfSize;
	unsigned long long m_fBackground;
	UIWidget();
	virtual ~UIWidget();
	
	/**impl of Widget **/
	virtual void initialize();
	virtual void update(double frameTime);
	virtual void render(double frameTime);
	
	/**impl of Drawable**/
	virtual void setDrawRectangle(float _left, float _top, float _width, float _height);
};


