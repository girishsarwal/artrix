/*
 * FTFontManager.cpp
 *
 *  Created on: 19-Jan-2017
 *      Author: gsarwal
 */

#include <FTFontManager.h>

namespace gtfx {

FTFontManager::FTFontManager() {
	// TODO Auto-generated constructor stub

}

FTFontManager::~FTFontManager() {
	// TODO Auto-generated destructor stub
}
bool FTFontManager::initialize(const std::string& root, const std::string& manifest){
	mRoot = root;
	mManifest = manifest;
	printf("+--------------------FONT MANAGER----------------------+\n");
	printf("Initializing...\n");
	printf("Looking for font definitions in %s \n", mRoot.c_str());

	return loadAllFonts();
}

bool FTFontManager::loadAllFonts(){
//	std::string manifest = mRoot+ "/" + mManifest;
//	tinyxml2::XMLDocument doc;
//	tinyxml2::XMLError result = doc.LoadFile(manifest.c_str());
//	if(result != tinyxml2::XML_SUCCESS){
//		printf("cannot open manifest %s", manifest.c_str());
//		return false;
//	}
//	for (tinyxml2::XMLNode *textureNode = doc.RootElement()->FirstChild(); textureNode; textureNode = textureNode->NextSibling()) {
//		Texture* texture = new Texture(textureNode);
//		texture->SetTextureRoot(mRoot);
//		texture->Initialize();
//		m_pInstance->Add(texture);
//	}
//	return true;
	return true;
}

void FTFontManager::Use(const std::string& name) {

}
void FTFontManager::shutdown() {

}
FTFontManager* FTFontManager::m_pInstance = NULL;
} /* namespace gtfx */
