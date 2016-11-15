/*
 * Texture.cpp
 *
 *  Created on: 15-Nov-2016
 *      Author: gsarwal
 */

#include <Texture.h>

Texture::Texture(){

}

Texture::~Texture() {

}

void Texture::use(){
	glActiveTexture(mTextureId);
}

uint Texture::GetTextureId() {
	return mTextureId;
}

void Texture::SetTextureId(uint textureId) {
	mTextureId = textureId;
}

const std::string& Texture::GetTextureFile() const {
	return mTextureFile;
}

void Texture::SetTextureFile(const std::string& file) {
	mTextureFile = file;
	mTextureId = SOIL_load_OGL_texture(
			mTextureFile.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	printf("\nTexture ID for %s is %d ", mTextureFile.c_str(), mTextureId);
}
