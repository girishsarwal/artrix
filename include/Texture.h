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
	std::string mTextureFile;
	bool mIsInialized;
public:
	Texture();
	void use();
	virtual ~Texture();
	uint GetTextureId();
	void SetTextureId(uint textureId);
	const std::string& GetTextureFile() const;
	void SetTextureFile(const std::string& file);
};

#endif /* INCLUDE_TEXTURE_H_ */
