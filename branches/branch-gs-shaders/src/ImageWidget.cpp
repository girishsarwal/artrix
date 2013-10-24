/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "afx.h"

void ImageWidget::onInitialize(){
	m_pPath = m_asAttributes.get("src").getValue().c_str();
	m_iTextureId = TM->getTexture(m_pPath);
	createGeometry();
}
void ImageWidget::createGeometry(){
	
	VertexColor vertices[] = 
	{
		{-90.0f, -90.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f},
		{ 90.0f, -90.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f},
		{ 90.0f,  90.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f}, 
		{-90.0f,  90.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f}, 
	};
	/*Vertex vertices[] = 
	{
		{-1.0f, -1.0f, 0.0f, },
		{ 1.0f, -1.0f, 0.0f, },
		{ 1.0f,  1.0f, 0.0f, }, 
		{-1.0f,  1.0f, 0.0f, }, 
	};*/
	
	m_iSizeVertex = sizeof(VertexColor);
	m_iSizeVertices = sizeof(vertices);
	GLuint indices[] = 
	{
		0, 1, 2,
		0, 2, 3,
	};
	m_iSizeIndices = sizeof(indices);
	
	m_iNumVertices = m_iSizeVertices / m_iSizeVertex;
	m_iNumTriangles = m_iSizeIndices / 3.0;
	/** all values have been set, copy the data **/
	m_pVertices = malloc(sizeof(vertices));
	m_pIndices = malloc(sizeof(indices));
	
	memcpy(m_pVertices, vertices, m_iSizeVertices);
	memcpy(m_pIndices, indices, m_iSizeIndices);
};
ImageWidget::ImageWidget() {
};

ImageWidget::~ImageWidget() {
	
};


void ImageWidget::onUpdate(double frameTime){
	
};

void ImageWidget::onRender(double frameTime){
	glUseProgram(SPM->getProgramId("vc"));
	glColor4ub((m_fBackground & 0x00FF0000) >> 0x10,
				(m_fBackground & 0x0000FF00) >> 0x08,
				m_fBackground & 0x000000FF,
				(m_fBackground & 0xFF000000) >> 0x18);
	glBindBuffer(GL_ARRAY_BUFFER, m_iVertexBuffer);			
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glVertexAttribPointer(0, VertexColor::SIZE_POSITION, GL_FLOAT, GL_FALSE, VertexColor::STRIDE, (GLvoid*)0);
	glVertexAttribPointer(1, VertexColor::SIZE_COLOR, GL_FLOAT, GL_FALSE, VertexColor::STRIDE, (GLvoid*)16);
		
	//glScalef(m_vSize.x, m_vSize.y, 1);
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, m_iTextureId);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawElements(GL_TRIANGLES, m_iSizeIndices, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, m_iSizeIndices/3);
	//glDisable(GL_TEXTURE_2D);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void ImageWidget::afterInitialize(){
	glGenBuffers(1, &m_iVertexBuffer);
	glGenBuffers(1, &m_iIndexBuffer);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_iVertexBuffer);
	glBufferData (GL_ARRAY_BUFFER, m_iSizeVertices, m_pVertices, GL_STATIC_DRAW);	
	
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_iSizeIndices, m_pIndices, GL_STATIC_DRAW);
}


