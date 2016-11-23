/*
 * Geometry.cpp
 *
 *  Created on: 23-Nov-2016
 *      Author: gsarwal
 */

#include "Geometry.h"

Geometry::Geometry() {
	mSizeVertex = 0;
	mSizeVertices = 0;
	mSizeIndex =  0;
	mSizeIndices = 0;

	mNumVertices = 0;
	mNumIndices = 0;
	mNumTriangles = 0;

	mVertexBufferId = 0;
	mIndexBufferId = 0;

	mVertexBuffer = NULL;
	mIndexBuffer = NULL;
}

Geometry::~Geometry() {
	// TODO Auto-generated destructor stub
}

void Geometry::CreatePlaneGeometry(Geometry** geometry, int vd, const Vector3& dimension) {

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

	if(NULL == (*geometry)) {
		*geometry = new Geometry();
	}

	float r = 0x00FF0000;
	float g = 0x0000FF00;
	float b = 0x0000FF00;
	float a = 0xFF000000;

	VertexColor vertices[] =
	{
		{-1, -1, 0.0f, r, g, b, a},
		{ 1, -1, 0.0f, r, g, b, a},
		{ 1,  1, 0.0f, r, g, b, a},
		{-1,  1, 0.0f, r, g, b, a},
	};


	(*geometry)->mSizeVertex = sizeof(vertices[0]);
	(*geometry)->mSizeVertices = sizeof(vertices);
	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3,
	};
	(*geometry)->mSizeIndex = sizeof(indices[0]);
	(*geometry)->mSizeIndices = sizeof(indices);

	(*geometry)->mNumVertices = (*geometry)->mSizeVertices / (*geometry)->mSizeVertex;
	(*geometry)->mNumIndices= (*geometry)->mSizeIndices/ (*geometry)->mSizeIndex;
	(*geometry)->mNumTriangles = (*geometry)->mSizeIndices / (3.0 * (*geometry)->mSizeIndex);
	/** all values have been set, copy the data **/
	(*geometry)->mVertexBuffer = malloc((*geometry)->mSizeVertices);
	(*geometry)->mIndexBuffer = malloc((*geometry)->mSizeIndices);

	memcpy((*geometry)->mVertexBuffer, vertices, (*geometry)->mSizeVertices);
	memcpy((*geometry)->mIndexBuffer, indices, (*geometry)->mSizeIndices);

	glGenBuffers(1, &((*geometry)->mVertexBufferId));
	glGenBuffers(1, &((*geometry)->mIndexBufferId));
}

void Geometry::Render(){
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
	glBufferData (GL_ARRAY_BUFFER, mSizeVertices, mVertexBuffer, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mSizeIndices, mIndexBuffer, GL_STATIC_DRAW);

	VertexColor::EnableAttribute(VertexColor::INDEX_POSITION);
	VertexColor::EnableAttribute(VertexColor::INDEX_COLOR);


	glDrawElements(GL_TRIANGLES, mSizeIndices, GL_UNSIGNED_INT, 0);

	VertexColor::DisableAttribute(VertexColor::INDEX_POSITION);
	VertexColor::DisableAttribute(VertexColor::INDEX_COLOR);

}

