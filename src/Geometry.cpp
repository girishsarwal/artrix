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

void Geometry::CreatePlaneGeometry(Geometry** geometry, int vd, const glm::vec3& dimension) {

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

	float r = 0.0f;
	float g = 1.0f;
	float b = 0.0f;
	float a = 1.0f;

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



	glGenVertexArrays(1, &((*geometry)->mVertexArrayId));
	glBindVertexArray((*geometry)->mVertexArrayId);

	glGenBuffers(1, &((*geometry)->mVertexBufferId));
	glBindBuffer(GL_ARRAY_BUFFER, (*geometry)->mVertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, (*geometry)->mSizeVertices, vertices, GL_STATIC_DRAW);


	glGenBuffers(1, &((*geometry)->mIndexBufferId));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (*geometry)->mIndexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (*geometry)->mSizeIndices, &indices[0], GL_STATIC_DRAW);
}

void Geometry::Render(){

	VertexColor::EnableAttribute(VertexColor::INDEX_POSITION);
	VertexColor::EnableAttribute(VertexColor::INDEX_COLOR);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
	glDrawElements(GL_TRIANGLES, mSizeIndices, GL_UNSIGNED_INT, (void*)0);
	VertexColor::DisableAttribute(VertexColor::INDEX_POSITION);
	VertexColor::DisableAttribute(VertexColor::INDEX_COLOR);
}

