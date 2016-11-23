#include "TextureManager.h"
TextureManager* TextureManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new TextureManager();
	}
	return m_pInstance;
}
bool TextureManager::initialize(const std::string& root, const std::string& manifest){
	mRoot = root;
	mManifest = manifest;
	printf("+--------------------TEXTURE MANAGER----------------------+\n");
	printf("Initializing...\n");
	printf("Looking for textures in %s \n", mRoot.c_str());
	return loadAllTextures();
}

bool TextureManager::loadAllTextures(){
	std::string manifest = mRoot+ "/" + mManifest;
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError result = doc.LoadFile(manifest.c_str());
	if(result != tinyxml2::XML_SUCCESS){
		printf("cannot open manifest %s", manifest.c_str());
		return false;
	}
	for (tinyxml2::XMLNode *textureNode = doc.RootElement()->FirstChild(); textureNode; textureNode = textureNode->NextSibling()) {
		Texture* texture = new Texture(textureNode);
		texture->SetTextureRoot(mRoot);
		TM->Add(texture);
	}
	return true;
}

void TextureManager::Use(const std::string& name) {
	Texture* t = Get(name);
	if(NULL == t) {
		printf("\nWARNING: Texture '%s' not found", name.c_str());
		return;
	}
	t->Use();
}
TextureManager* TextureManager::m_pInstance = NULL;
