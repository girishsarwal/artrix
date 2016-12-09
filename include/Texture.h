/*
 * Texture.h
 *
 *  Created on: 15-Nov-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_TEXTURE_H_
#define INCLUDE_TEXTURE_H_

#include "KeyManageable.h"

class Texture:
	public KeyManageable {
private:
	uint mTextureId;
	std::string mFile;
	std::string mRoot;
	std::string mSource;
	std::string mType;
	bool mIsInitialized;

	unsigned char* imageData;
public:
	Texture();
	void Use();
	virtual ~Texture();
	Texture(tinyxml2::XMLNode*);
	uint GetTextureId();
	void SetTextureId(uint textureId);
	const std::string& GetTextureRoot() const;
	void SetTextureRoot(const std::string& file);
	const std::string& GetTextureSource() const;
	void SetTextureSource(const std::string& type);
	const std::string& GetTextureType() const;
	void SetTextureType(const std::string& type);

	bool GetIsInitialized() const;
	void Initialize();
	void BeforeInitialize();
	void AfterInitialize();

	string dump() const;
	void Print();
	friend ostream& operator<<(ostream& stream, const Texture& texture);
};

#endif /* INCLUDE_TEXTURE_H_ */
