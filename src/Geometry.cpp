/*
 * Geometry.cpp
 *
 *  Created on: 23-Nov-2016
 *      Author: gsarwal
 */

#include "Geometry.h"
namespace gtfx {
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

	mVertexDataPtr = NULL;
	mIndicesDataPtr = NULL;

}

Geometry::~Geometry() {
	// TODO Auto-generated destructor stub
}

void Geometry::CreatePlaneGeometry(gtfx::Geometry* geometry, int vertexDescriptor, const glm::vec3& dimensions) {
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

	geometry->mSizeVertex = sizeof(vertices[0]);
	geometry->mSizeVertices = sizeof(vertices);
	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3,
	};
	geometry->mSizeIndex = sizeof(indices[0]);
	geometry->mSizeIndices = sizeof(indices);

	geometry->mNumVertices = geometry->mSizeVertices / geometry->mSizeVertex;
	geometry->mNumIndices= geometry->mSizeIndices/ geometry->mSizeIndex;
	geometry->mNumTriangles = geometry->mSizeIndices / (3.0 * geometry->mSizeIndex);

	geometry->mVertexDataPtr = malloc(geometry->mSizeVertices);
	geometry->mIndicesDataPtr = malloc(geometry->mSizeIndices);

	memcpy(geometry->mVertexDataPtr, vertices, geometry->mSizeVertices);
	memcpy(geometry->mIndicesDataPtr, indices, geometry->mSizeIndices);

}
}


