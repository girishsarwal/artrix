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
class Geometry {
private:
	GLint	mSizeVertex;
	GLint	mSizeVertices;
	GLint	mSizeIndex;
	GLint	mSizeIndices;

	GLint 	mNumVertices;
	GLint	mNumIndices;
	GLint	mNumTriangles;

	GLuint	mVertexArrayId;
	GLuint	mIndexArrayId;

	GLuint	mVertexBufferId;
	GLuint	mIndexBufferId;

	GLvoid*	mVertexBuffer;
	GLvoid*	mIndexBuffer;

public:
	static void CreatePlaneGeometry(Geometry**, int, const glm::vec3&);
	Geometry();
	void Render();
	virtual ~Geometry();
};

#endif /* INCLUDE_GEOMETRY_H_ */
