/*
 * ImageWidget.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: girish
 */

#include "ImageWidget.h"

void ImageWidget::onInitialize(){
//	m_pPath = m_asAttributes.get("src").getValue().c_str();
//	m_iTextureId = TM->getTexture(m_pPath);
//	m_pShadingProgram = SPM->getProgram("vc");
	
//	createGeometry();
}
void ImageWidget::createGeometry(){
//	/**generate the background rgb components **/
//	float r = (m_fBackground & 0x00FF0000) >> 0x10;
//	float g = (m_fBackground & 0x0000FF00) >> 0x08;
//	float b = m_fBackground & 0x000000FF;
//	float a = (m_fBackground & 0xFF000000) >> 0x18;
//
//	/*VertexColorTexture vertices[] =
//	{
//		{-m_vSize.x, -m_vSize.y, 0.0f, r, g, b, a, 0.0f, 0.0f},
//		{ m_vSize.x, -m_vSize.y, 0.0f, r, g, b, a, 1.0f, 0.0f},
//		{ m_vSize.x,  m_vSize.y, 0.0f, r, g, b, a, 1.0f, 1.0f},
//		{-m_vSize.x,  m_vSize.y, 0.0f, r, g, b, a, 0.0f, 1.0f},
//	};*/
//	VertexColor vertices[] =
//	{
//		{-1, -1, 0.0f, r, g, b, a},
//		{ 1, -1, 0.0f, r, g, b, a},
//		{ 1,  1, 0.0f, r, g, b, a},
//		{-1,  1, 0.0f, r, g, b, a},
//	};
//
//
//	m_iSizeVertex = sizeof(vertices[0]);
//	m_iSizeVertices = sizeof(vertices);
//	GLuint indices[] =
//	{
//		0, 1, 2,
//		0, 2, 3,
//	};
//	m_iSizeIndices = sizeof(indices);
//
//	m_iNumVertices = m_iSizeVertices / m_iSizeVertex;
//	m_iNumTriangles = m_iSizeIndices / 3.0;
//	/** all values have been set, copy the data **/
//	m_pVertices = malloc(m_iSizeVertices);
//	m_pIndices = malloc(m_iSizeIndices);
//
//	memcpy(m_pVertices, vertices, m_iSizeVertices);
//	memcpy(m_pIndices, indices, m_iSizeIndices);
};
ImageWidget::ImageWidget() {
};

ImageWidget::~ImageWidget() {
	
};


void ImageWidget::onUpdate(double frameTime){
	
};

void ImageWidget::onRender(double frameTime){
	
//	VertexColorTexture::EnableAttribute(VertexColorTexture::INDEX_POSITION);
//	VertexColorTexture::EnableAttribute(VertexColorTexture::INDEX_COLOR);
//	VertexColorTexture::EnableAttribute(VertexColorTexture::INDEX_TEX0);
//
//	m_pShadingProgram->setActive();
//
//
//
//	glBindTexture(GL_TEXTURE_2D, m_iTextureId);
//
//	glDrawElements(GL_TRIANGLES, m_iSizeIndices, GL_UNSIGNED_INT, 0);
//
//	VertexColorTexture::DisableAttribute(VertexColorTexture::INDEX_POSITION);
//	VertexColorTexture::DisableAttribute(VertexColorTexture::INDEX_COLOR);
//	VertexColorTexture::DisableAttribute(VertexColorTexture::INDEX_TEX0);
	
}

void ImageWidget::afterInitialize(){
//	glGenBuffers(1, &m_iVertexBuffer);
//	glGenBuffers(1, &m_iIndexBuffer);
//
//	glBindBuffer(GL_ARRAY_BUFFER, m_iVertexBuffer);
//	glBufferData (GL_ARRAY_BUFFER, m_iSizeVertices, m_pVertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iIndexBuffer);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_iSizeIndices, m_pIndices, GL_STATIC_DRAW);
			
	
}


