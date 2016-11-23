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
#include "Vector3.h"
class Geometry {
private:
	GLint	mSizeVertex;
	GLint	mSizeVertices;
	GLint	mSizeIndex;
	GLint	mSizeIndices;

	GLint 	mNumVertices;
	GLint	mNumIndices;
	GLint	mNumTriangles;

	GLuint	mVertexBufferId;
	GLuint	mIndexBufferId;

	GLvoid*	mVertexBuffer;
	GLvoid*	mIndexBuffer;

public:
	static void CreatePlaneGeometry(Geometry**, int, const Vector3&);
	Geometry();
	void Render();
	virtual ~Geometry();
};

#endif /* INCLUDE_GEOMETRY_H_ */
