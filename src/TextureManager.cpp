#include "TextureManager.h"
TextureManager* TextureManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new TextureManager();
	}
	return m_pInstance;
}
bool TextureManager::initialize(const std::string& root){
	m_root = root;
	printf("+--------------------TEXTURE MANAGER----------------------+\n");
	printf("Initializing...\n");
	printf("Looking for textures in %s \n", m_root.c_str());
	loadAllTextures();
}

void TextureManager::loadAllTextures(){
	printf("Loading textures\n");
	DIR* dir;
	dirent* entry;
	dir = opendir(m_root.c_str());
	if(NULL == dir){
		printf("Error opening texture directory '%s'\n", m_root.c_str());
		return;
	}
	chdir(m_root.c_str());
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
void TextureManager::useTexture(const std::string& textureName){
	/*glBindTexture(GL_TEXTURE_2D, getTexture(textureName));*/
}
TextureManager* TextureManager::m_pInstance = NULL;
