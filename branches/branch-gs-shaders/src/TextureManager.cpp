#include "afx.h"
TextureManager* TextureManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new TextureManager();
	}
	return m_pInstance;
}
void TextureManager::initialize(){
	std::string textureRoot("/usr/share/artrix/images");
	loadAllTextures(textureRoot);
}

void TextureManager::loadAllTextures(std::string& textureRoot){
	printf("Loading textures\n");
	DIR* dir;
	dirent* entry;
	dir = opendir(textureRoot.c_str());
	if(NULL == dir){
		printf("Error opening texture directory '%s'\n", textureRoot.c_str());
		return;
	}
	chdir(textureRoot.c_str());
	while(NULL != (entry = readdir(dir))){
		if(entry->d_type != DT_DIR){
			std::string texture = std::string(entry->d_name);
			loadTexture(texture);
		}
	}
};

void TextureManager::loadTexture(std::string& path){
	uint textureId = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT); 
	m_Textures[path] = textureId;
	printf("Texture ID for %s is %d\n", path.c_str(), textureId);
};

uint TextureManager::getTexture(std::string& name){
	return m_Textures[name];
}

TextureManager* TextureManager::m_pInstance = NULL;
