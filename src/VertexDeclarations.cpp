#include "afx.h"
#include "VertexDeclarations.h"

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



const int VertexTextureNormal::INDEX_POSITION	= 0;
const int VertexTextureNormal::INDEX_TEX0		= 1;
const int VertexTextureNormal::INDEX_NORMAL		= 2;
const int VertexTextureNormal::OFFSET_POSITION 	= 0;
const int VertexTextureNormal::OFFSET_TEX0		= 12;
const int VertexTextureNormal::OFFSET_NORMAL	= 20;
const int VertexTextureNormal::SIZE_POSITION	= 3;
const int VertexTextureNormal::SIZE_TEX0		= 2;
const int VertexTextureNormal::SIZE_NORMAL		= 3;
const int VertexTextureNormal::STRIDE			= 32;
const int VertexTextureNormal::VertexAttribInfo[3][2] = {
	{SIZE_POSITION, OFFSET_POSITION},
	{SIZE_TEX0, OFFSET_TEX0},
	{SIZE_NORMAL, OFFSET_NORMAL},
};
void VertexTextureNormal::EnableAttribute(int index){
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, VertexAttribInfo[index][0], GL_FLOAT, GL_FALSE, STRIDE, (GLvoid*)VertexAttribInfo[index][1]);
};
void VertexTextureNormal::DisableAttribute(int index){
	glDisableVertexAttribArray(index);
};


const int VertexColorTextureNormal::INDEX_POSITION	= 0;
const int VertexColorTextureNormal::INDEX_COLOR		= 1;
const int VertexColorTextureNormal::INDEX_TEX0		= 2;
const int VertexColorTextureNormal::INDEX_NORMAL	= 3;
const int VertexColorTextureNormal::OFFSET_POSITION	= 0;
const int VertexColorTextureNormal::OFFSET_COLOR	= 12;
const int VertexColorTextureNormal::OFFSET_TEX0 	= 28;
const int VertexColorTextureNormal::OFFSET_NORMAL 	= 36;
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
}
;

const int VertexTexture::INDEX_POSITION	= 0;
const int VertexTexture::INDEX_TEX0		= 1;
const int VertexTexture::OFFSET_POSITION= 0;
const int VertexTexture::OFFSET_TEX0 	= 12;
const int VertexTexture::SIZE_POSITION 	= 3;
const int VertexTexture::SIZE_TEX0 		= 2;
const int VertexTexture::STRIDE			= 20;
const int VertexTexture::VertexAttribInfo[2][2] = {
	{SIZE_POSITION, OFFSET_POSITION},
	{SIZE_TEX0, OFFSET_TEX0},
};
void VertexTexture::EnableAttribute(int index){
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, VertexAttribInfo[index][0], GL_FLOAT, GL_FALSE, STRIDE, (GLvoid*)VertexAttribInfo[index][1]);
};
void VertexTexture::DisableAttribute(int index){
	glDisableVertexAttribArray(index);
}

uint VertexAttribute::GetElementSize() const {
	return mElementSize;
}

uint VertexAttribute::GetNumberOfElements() const {
	return mNumberOfElements;
}

uint VertexAttribute::GetOffset() const {
	return mOffset;
}
void VertexAttribute::SetOffset(uint offset) {
	mOffset = offset;
}

uint VertexAttribute::GetSizeInBytes() const {
	return mSizeInBytes;
}

VertexAttribute::VertexAttribute()
	: mType (UNDEFINED)
	, mOffset (0)
	, mNumberOfElements (0)
	, mElementSize (0)
	, mSizeInBytes (mNumberOfElements * mElementSize){
}

VertexAttribute::VertexAttribute(VERTEXATTRIBUTETYPE type, uint numberOfElements, uint elementSize)
	: mType (type)
	, mOffset (0)
	, mNumberOfElements (numberOfElements)
	, mElementSize (elementSize)
	, mSizeInBytes (mNumberOfElements * mElementSize){
}

VERTEXATTRIBUTETYPE VertexAttribute::GetType() const {
	return mType;
}

uint VertexDefinition::GetSizeInBytes() const {
	return mSizeInBytes;
}

void VertexDefinition::AddVertexAttribute(VertexAttribute* va) {
	va->SetIndex(++mNextIndex);
	va->SetOffset(mSizeInBytes);
	mAttributes[va->GetType()]= va;
	mSizeInBytes += va->GetSizeInBytes();
}

void VertexDefinition::EnableVertexAttributes() {
	std::map<VERTEXATTRIBUTETYPE, VertexAttribute*>::iterator va = mAttributes.begin();
	while(va != mAttributes.end()) {
		glEnableVertexAttribArray(va->second->GetIndex());
		glVertexAttribPointer(va->second->GetIndex(), va->second->GetNumberOfElements(), GL_FLOAT, GL_FALSE, mSizeInBytes, (GLvoid*)va->second->GetOffset());
		va++;
	}
}

void VertexDefinition::DisableVertexAttributes() {
	std::map<VERTEXATTRIBUTETYPE, VertexAttribute*>::iterator va = mAttributes.begin();
	while(va != mAttributes.end()) {
		glDisableVertexAttribArray(va->second->GetIndex());
		va++;
	}
}

VertexAttribute* VertexDefinition::GetVertexAttribute(VERTEXATTRIBUTETYPE type) const{
	std::map<VERTEXATTRIBUTETYPE, VertexAttribute*>::const_iterator  it = mAttributes.find(type);
	if (it == mAttributes.end())
	    return NULL;
	return it->second;
}

VertexDefinition::VertexDefinition()
	: mSizeInBytes(0)
	, mNextIndex (-1) {
}

void VertexAttribute::SetIndex(uint index) {
	mIndex = index;
}
uint VertexAttribute::GetIndex() const {
	return mIndex;
}


bool VertexAttribute::operator ==(const VertexAttribute& rhs) const {
	return mType == rhs.mType;
}

bool VertexAttribute::operator !=(const VertexAttribute& rhs) const {
	return !(mType == rhs.mType);
}
