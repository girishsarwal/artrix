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

	mVertexDataBufferSize = 0;
	mIndexDataBufferSize = 0;

	mVertexDataBufferPtr = NULL;
	mIndexDataBufferPtr = NULL;
}

Geometry::~Geometry() {
	// TODO Auto-generated destructor stub
}

void Geometry::CreatePlaneGeometry(gtfx::Geometry* geometry, int vertexDescriptor, const glm::vec3& dimensions) {
	float r = 1.0f;
	float g = 1.0f;
	float b = 0.0f;
	float a = 0.40f;

	VertexColorTextureNormal vertices [] =
	{
			{-1.0f, -1.0f, 0.0f, r, g, b, a, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
			{ 1.0f, -1.0f, 0.0f, r, g, b, a, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f },
			{ 1.0f,  1.0f, 0.0f, r, g, b, a, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
			{-1.0f,  1.0f, 0.0f, r, g, b, a, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f },
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
void Geometry::CreatePlaneGeometry(gtfx::Geometry* geometry, const VertexDefinition& vd, const glm::vec3& dimension, const glm::vec3& divisions) {
	if(NULL == geometry) {
		geometry = new Geometry();
	}

	geometry->mNumVertices = (divisions.x + 2) * (divisions.y + 2);
	geometry->mNumTriangles = (divisions.x + 1) * (divisions.y + 1) * 2;
	geometry->mNumIndices = geometry->mNumTriangles * 3;

	geometry->mVertexDataBufferSize = vd.GetSizeInBytes() * geometry->mNumVertices;
	geometry->mIndexDataBufferSize = geometry->mNumVertices * sizeof(uint);

	geometry->mVertexDataPtr = malloc(geometry->mVertexDataBufferSize );
	geometry->mIndicesDataPtr= malloc(geometry->mIndexDataBufferSize );


	/** build the vertices for a plane **/

	float divWidth = 1.0f / (divisions.x + 1);
	float divHeight = 1.0f / (divisions.y + 1);
	glm::vec3 vec3element;
	GLvoid* basePtr = geometry->mVertexDataPtr;
	for (int y = 0; y < divisions.y + 2; y++){
		for (int x = 0; x < divisions.x + 2; x++) {
			VertexAttribute* va = vd.GetVertexAttribute(POSITION);
			if(NULL != va) {
				//TODO: Apply scaling based on dimension, take a call if dimension needs to be here or in the pipeline
				vec3element = glm::lerp(glm::vec3(-1, -1, 0), glm::vec3(1, 1, 0), glm::vec3(divWidth * x, divHeight * y, 0));
				memcpy(basePtr + va->GetOffset(), &vec3element.x, va->GetSizeInBytes());
			 /** patch the vertex position in **/
			}
			va = vd.GetVertexAttribute(COLOR);
			if(NULL != va) {
			 /** patch the vertex position in **/
			}
			va = vd.GetVertexAttribute(TEXTURE0);
			if(NULL != va) {
			/** patch the vertex position in **/
				memcpy((basePtr + va->GetOffset()), &vec3element.x, va->GetSizeInBytes());
			}
			va = vd.GetVertexAttribute(NORMAL);
			if(NULL != va) {
				/** patch the vertex position in **/
				vec3element.x = vec3element.y = vec3element.z = 0.0f;
				memcpy((basePtr + va->GetOffset()), &vec3element.x, va->GetSizeInBytes());
			}
		}
		basePtr += vd.GetSizeInBytes();
	}
	/** Build the indices **/

}
}


