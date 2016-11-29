/*
 * Geometry.h
 *
 *  Created on: 23-Nov-2016
 *      Author: gsarwal
 */

#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "afx.h"
#include "VertexDeclarations.h"
namespace gtfx {
class Geometry {
public:
	GLint	mSizeVertex;
	GLint	mSizeVertices;
	GLint	mSizeIndex;
	GLint	mSizeIndices;

	GLint 	mNumVertices;
	GLint	mNumIndices;
	GLint	mNumTriangles;

	GLuint	mVertexArrayId;

	GLuint	mVertexBufferId;
	GLuint	mIndexBufferId;

	GLvoid* mVertexDataPtr;
	GLvoid* mIndicesDataPtr;

public:

	Geometry();
	virtual ~Geometry();
	static void CreatePlaneGeometry(gtfx::Geometry* geometry, int, const glm::vec3&);
};
}
#endif /* INCLUDE_GEOMETRY_H_ */
