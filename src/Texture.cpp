/*
 * Texture.cpp
 *
 *  Created on: 15-Nov-2016
 *      Author: gsarwal
 */

#include <Texture.h>

Texture::Texture(){
	mIsInitialized = false;
	SetDefaultName(string("Texture"));
}
Texture::Texture(tinyxml2::XMLNode* node ){
	mIsInitialized = false;
	tinyxml2::XMLElement* elem = node->ToElement();
	mName = elem->Attribute("name");
	mType = elem->Attribute("type");
	mSource = elem->Attribute("source");
	mRoot = ".";
	SetName(elem->Attribute("name"));
}
Texture::~Texture() {

}

void Texture::Use(){
	if(!mIsInitialized) {
		Initialize();
	}
	glActiveTexture(mId);
}

uint Texture::GetTextureId() {
	return mId;
}

void Texture::SetTextureId(uint textureId) {
	mId = textureId;
}

const std::string& Texture::GetTextureType() const {
	return mType;
}
void Texture::SetTextureType(const std::string& type) {
	mType = type;
}

const std::string& Texture::GetTextureRoot() const {
	return mRoot;
}
void Texture::SetTextureRoot(const std::string& root) {
	mRoot = root;
}


const std::string& Texture::GetTextureSource() const {
	return mSource;
}
void Texture::SetTextureSource(const std::string& source) {
	mSource = source;
	mFile = mRoot + "/" + mSource;
	mTextureId = SOIL_load_OGL_texture(
			mFile.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	Print();
}


bool Texture::GetIsInitialized() const {
    return mIsInitialized;
}
void Texture::Initialize() {
    SetTextureSource(mSource);     /** I know this sounds stupid to do but C++ makes objects like an onion, inside out and we need to call some virt func during creation **/
    SetTextureType(mType);
    mIsInitialized = true;
}


string Texture::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Texture::Print() {
	printf("\nTexture - %d - %s", mTextureId, dump().c_str());

}

ostream& operator<<(ostream& stream, const Texture& texture) {
    stream << "<texture type=\"" << texture.mType.c_str() << "\" source=\"" << texture.mSource.c_str() << "\" name =\"" << texture.mName.c_str() << "\">\n";
    return stream;
}


