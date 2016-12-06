#include "afx.h"
#include "VertexDeclarations.h"
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
