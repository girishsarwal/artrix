#include "afx.h"

const int Vertex::OFFSET_POSITION 				= 0;
const int Vertex::INDEX_POSITION				= 0;
const int Vertex::SIZE_POSITION					= 3;
const int Vertex::STRIDE						= 12;
const int Vertex::VertexAttribInfo[1][2] = {
	{SIZE_POSITION, OFFSET_POSITION},
};
void Vertex::EnableAttribute(int index){
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, VertexAttribInfo[index][0], GL_FLOAT, GL_FALSE, STRIDE, (GLvoid*)VertexAttribInfo[index][1]);
};
void Vertex::DisableAttribute(int index){
	glDisableVertexAttribArray(index);
};

const int VertexColor::INDEX_POSITION			= 0;
const int VertexColor::INDEX_COLOR				= 1;
const int VertexColor::OFFSET_POSITION			= 0;
const int VertexColor::OFFSET_COLOR				= 12;
const int VertexColor::SIZE_POSITION			= 3;
const int VertexColor::SIZE_COLOR				= 4;
const int VertexColor::STRIDE	 				= 28;
const int VertexColor::VertexAttribInfo[2][2] = {
	{SIZE_POSITION, OFFSET_POSITION},
	{SIZE_COLOR, OFFSET_COLOR},
};
void VertexColor::EnableAttribute(int index){
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, VertexAttribInfo[index][0], GL_FLOAT, GL_FALSE, STRIDE, (GLvoid*)VertexAttribInfo[index][1]);
};
void VertexColor::DisableAttribute(int index){
	glDisableVertexAttribArray(index);
};


const int VertexColorTexture::INDEX_POSITION	= 0;
const int VertexColorTexture::INDEX_COLOR		= 1;
const int VertexColorTexture::INDEX_TEX0		= 2;
const int VertexColorTexture::OFFSET_POSITION 	= 0;
const int VertexColorTexture::OFFSET_COLOR		= 12;
const int VertexColorTexture::OFFSET_TEX0		= 28;
const int VertexColorTexture::SIZE_POSITION		= 3;
const int VertexColorTexture::SIZE_COLOR		= 4;
const int VertexColorTexture::SIZE_TEX0			= 2;
const int VertexColorTexture::STRIDE			= 36;
const int VertexColorTexture::VertexAttribInfo[3][2] = {
	{SIZE_POSITION, OFFSET_POSITION},
	{SIZE_COLOR, OFFSET_COLOR},
	{SIZE_TEX0, OFFSET_TEX0},
};
void VertexColorTexture::EnableAttribute(int index){
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, VertexAttribInfo[index][0], GL_FLOAT, GL_FALSE, STRIDE, (GLvoid*)VertexAttribInfo[index][1]);
};
void VertexColorTexture::DisableAttribute(int index){
	glDisableVertexAttribArray(index);
};


const int VertexColorTextureNormal::INDEX_POSITION	= 0;
const int VertexColorTextureNormal::INDEX_COLOR		= 1;
const int VertexColorTextureNormal::INDEX_TEX0		= 2;
const int VertexColorTextureNormal::INDEX_NORMAL	= 3;
const int VertexColorTextureNormal::OFFSET_POSITION	= 0;
const int VertexColorTextureNormal::OFFSET_COLOR	= 12;
const int VertexColorTextureNormal::OFFSET_TEX0 	= 28;
const int VertexColorTextureNormal::OFFSET_NORMAL 	= 32;
const int VertexColorTextureNormal::SIZE_POSITION 	= 3;
const int VertexColorTextureNormal::SIZE_COLOR 		= 4;
const int VertexColorTextureNormal::SIZE_TEX0 		= 2;
const int VertexColorTextureNormal::SIZE_NORMAL 	= 3;
const int VertexColorTextureNormal::STRIDE			= 48;
const int VertexColorTextureNormal::VertexAttribInfo[4][2] = {
	{SIZE_POSITION, OFFSET_POSITION},
	{SIZE_COLOR, OFFSET_COLOR},
	{SIZE_TEX0, OFFSET_TEX0},
	{SIZE_NORMAL, OFFSET_NORMAL},
};
void VertexColorTextureNormal::EnableAttribute(int index){
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, VertexAttribInfo[index][0], GL_FLOAT, GL_FALSE, STRIDE, (GLvoid*)VertexAttribInfo[index][1]);
};
void VertexColorTextureNormal::DisableAttribute(int index){
	glDisableVertexAttribArray(index);
};

