/*
 * Geometry.cpp
 *
 *  Created on: 23-Nov-2016
 *      Author: gsarwal
 */

#include <GL/glew.h>
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

void Geometry::CreatePlaneGeometry(gtfx::Geometry* geometry, const VertexDefinition& vd, const glm::vec3& dimension, const glm::vec3& divisions) {
	if(NULL == geometry) {
		geometry = new Geometry();
	}

	geometry->mNumVertices = (divisions.x + 2) * (divisions.y + 2);
	geometry->mNumTriangles = (divisions.x + 1) * (divisions.y + 1) * 2;
	geometry->mNumIndices = geometry->mNumTriangles * 3;

	geometry->mVertexDataBufferSize = vd.GetSizeInBytes() * geometry->mNumVertices;
	geometry->mIndexDataBufferSize = geometry->mNumIndices * sizeof(uint);

	//float vdata[100];
	//uint idata[100];

	//memset(vdata, 0, sizeof(float) * 100);
	//memset(idata, 0 , sizeof(uint) * 100);

	geometry->mVertexDataPtr = (GLfloat*)malloc(geometry->mVertexDataBufferSize );
	geometry->mIndicesDataPtr= (GLuint*)malloc(geometry->mIndexDataBufferSize );

	//geometry->mVertexDataPtr = &vdata[0];
	//geometry->mIndicesDataPtr= &idata[0];

	/** build the vertices for a plane **/

	float divWidth = 1.0f / (divisions.x + 1);
	float divHeight = 1.0f / (divisions.y + 1);
	glm::vec3 vec3element;
	GLvoid* basePtrVertices = geometry->mVertexDataPtr;
	for (int y = 0; y < divisions.y + 2; y++){
		for (int x = 0; x < divisions.x + 2; x++) {
			VertexAttribute* va = vd.GetVertexAttribute(POSITION);
			if(NULL != va) {
				//TODO: Apply scaling based on dimension, take a call if dimension needs to be here or in the pipeline
				/** patch the vertex position in **/
				vec3element = glm::lerp(glm::vec3(-1, -1, 0), glm::vec3(1, 1, 0), glm::vec3(divWidth * x, divHeight * y, 0));
				memcpy(basePtrVertices + va->GetOffset(), &vec3element.x, va->GetSizeInBytes());
			}
			va = vd.GetVertexAttribute(COLOR);
			if(NULL != va) {
				/** patch the vertex position in **/
			}
			va = vd.GetVertexAttribute(TEXTURE0);
			if(NULL != va) {
			/** patch the vertex position in **/
				vec3element = glm::lerp(glm::vec3(0, 0, 0), glm::vec3(1, 1, 0), glm::vec3(divWidth * x, divHeight * y, 0));
				memcpy(basePtrVertices + va->GetOffset(), &vec3element.x, va->GetSizeInBytes());
			}
			va = vd.GetVertexAttribute(NORMAL);
			if(NULL != va) {
				/** patch the vertex position in **/
				vec3element.x = vec3element.y = vec3element.z = 0.0f;
				memcpy((basePtrVertices + va->GetOffset()), &vec3element.x, va->GetSizeInBytes());
			}
			basePtrVertices += vd.GetSizeInBytes();
		}
	}

	geometry->mSizeVertices = geometry->mVertexDataBufferSize;

	/** Build the indices **/
	GLvoid* basePtrIndices = geometry->mIndicesDataPtr;
	for (int y = 0; y < divisions.y + 1; y++){
		for (int x = 0; x < divisions.x + 1; x++) {
			uint topLeft = (y * (divisions.x + 2)) + x;
			uint topRight = topLeft + 1;
			uint bottomLeft = (y + 1) * (divisions.x + 2) + x;
			uint bottomRight = bottomLeft + 1;

			uint quadIndices[6] = {
				topLeft, topRight, bottomLeft,
				bottomLeft, topRight, bottomRight
			};
			memcpy(basePtrIndices, quadIndices, sizeof(uint) * 6);
			basePtrIndices += sizeof(uint) * 6;
		}
	}
	geometry->mSizeIndices = geometry->mIndexDataBufferSize;
}
}


