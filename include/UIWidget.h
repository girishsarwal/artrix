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

class UIWidget :
		public Widget,
		public Renderable {

protected:	

	
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
	UIWidget();
	UIWidget(tinyxml2::XMLNode*);
	virtual ~UIWidget();
	virtual void OnInitialize();
	virtual void OnUpdate(double gameTime);
};


