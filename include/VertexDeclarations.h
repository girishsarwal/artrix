#ifndef VERTEXDECLARATAIONS_H
#define VERTEXDECLARATAIONS_H
#pragma pack(1)			 
struct Vertex{
public:
	float x;
	float y;
	float z;
	static const int INDEX_POSITION;
	static const int OFFSET_POSITION;
	static const int SIZE_POSITION;
	static const int STRIDE;
	static const int VertexAttribInfo[1][2];
	static void EnableAttribute(int);
	static void DisableAttribute(int);
};

struct VertexColor{
public:
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
	float a;
	static const int INDEX_POSITION;
	static const int INDEX_COLOR;
	static const int OFFSET_POSITION;
	static const int OFFSET_COLOR;
	static const int SIZE_POSITION;
	static const int SIZE_COLOR;
	static const int STRIDE;
	static const int VertexAttribInfo[2][2];
	static void EnableAttribute(int);
	static void DisableAttribute(int);
};

struct VertexColorTexture{
public:
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
	float a;
	float u;
	float v;
	static const int INDEX_POSITION;
	static const int INDEX_COLOR;
	static const int INDEX_TEX0;
	static const int OFFSET_POSITION;
	static const int OFFSET_COLOR;
	static const int OFFSET_TEX0;
	static const int SIZE_POSITION;
	static const int SIZE_COLOR;
	static const int SIZE_TEX0;
	static const int STRIDE;
	static const int VertexAttribInfo[3][2];
	static void EnableAttribute(int);
	static void DisableAttribute(int);
};
struct VertexColorTextureNormal{
public:
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
	float a;
	float u;
	float v;
	float nx;
	float ny;
	float nz;
	static const int INDEX_POSITION;
	static const int INDEX_COLOR;
	static const int INDEX_TEX0;
	static const int INDEX_NORMAL;
	static const int OFFSET_POSITION;
	static const int OFFSET_COLOR;
	static const int OFFSET_TEX0;
	static const int OFFSET_NORMAL;
	static const int SIZE_POSITION;
	static const int SIZE_COLOR;
	static const int SIZE_TEX0;
	static const int SIZE_NORMAL;
	static const int STRIDE;
	static const int VertexAttribInfo[4][2];
	static void EnableAttribute(int);
	static void DisableAttribute(int);
};


class VertexAttribute {

};
#endif
