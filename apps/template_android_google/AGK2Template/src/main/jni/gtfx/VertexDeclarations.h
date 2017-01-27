#ifndef VERTEXDECLARATAIONS_H
#define VERTEXDECLARATAIONS_H
#pragma pack(1)			 
enum VERTEXATTRIBUTETYPE {
	UNDEFINED,
	POSITION,
	NORMAL,
	COLOR,
	TEXTURE0,
	TEXTURE1,
	TEXTURE2,
	TEXTURE3,
	TEXTURE4,
	TEXTURE5,
	TEXTURE6,
	TEXTURE7,
	BINORMAL,
	TANGENT,
};


class VertexAttribute {
public:
	uint GetElementSize() const;
	uint GetNumberOfElements() const;
	uint GetOffset() const;
	void SetOffset(uint offset);
	uint GetSizeInBytes() const;
	VERTEXATTRIBUTETYPE GetType() const;
	VertexAttribute();
	VertexAttribute(VERTEXATTRIBUTETYPE type, uint numberOfElements, uint elementSize);
	void SetIndex(uint index);
	uint GetIndex() const;
	bool operator==(const VertexAttribute& rhs) const;
	bool operator!=(const VertexAttribute& rhs) const;
private:
	VERTEXATTRIBUTETYPE mType;
	uint mIndex;
	uint mOffset;
	uint mElementSize;
	uint mNumberOfElements;
	uint mSizeInBytes;
};
class VertexDefinition {
private:
	std::map<VERTEXATTRIBUTETYPE, VertexAttribute*> mAttributes;
	uint mSizeInBytes;
	uint mNextIndex;
public:
	void AddVertexAttribute(VertexAttribute* va);
	void EnableVertexAttributes();
	void DisableVertexAttributes();
	VertexAttribute* GetVertexAttribute(VERTEXATTRIBUTETYPE) const;
	uint GetSizeInBytes() const;
	VertexDefinition();
};

#endif
