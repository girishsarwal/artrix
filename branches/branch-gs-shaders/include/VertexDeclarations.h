#include "afx.h"
#pragma pack(1)
struct Vertex{
public:
	float x;
	float y;
	float z;
	static const int OFFSET_POSITION;
	static const int SIZE_POSITION;
	static const int STRIDE;
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
	static const int OFFSET_POSITION;
	static const int OFFSET_COLOR;
	static const int SIZE_POSITION;
	static const int SIZE_COLOR;
	static const int STRIDE;
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
	static const int OFFSET_POSITION;
	static const int OFFSET_COLOR;
	static const int OFFSET_TEX0;
	static const int SIZE_POSITION;
	static const int SIZE_COLOR;
	static const int SIZE_TEX0;
	static const int STRIDE;
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
	static const int OFFSET_POSITION;
	static const int OFFSET_COLOR;
	static const int OFFSET_TEX0;
	static const int OFFSET_NORMAL;
	static const int SIZE_POSITION;
	static const int SIZE_COLOR;
	static const int SIZE_TEXT0;
	static const int SIZE_NORMAL;
};

