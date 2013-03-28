#include "afx.h"
TextureManager* TextureManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new TextureManager();
	}
	return m_pInstance;
}
void TextureManager::initialize(){
	loadAllTextures("/usr/share/artrix/images");
}

void TextureManager::loadAllTextures(const char* textureRoot){
	printf("Loading textures\n");
	DIR* dir;
	dirent* entry;
	dir = opendir(textureRoot);
	if(NULL == dir){
		printf("Error opening texture directory '%s'\n", textureRoot);
		return;
	}
	chdir(textureRoot);
	while(NULL != (entry = readdir(dir))){
		if(entry->d_type != DT_DIR){
     		uint tex_Id = SOIL_load_OGL_texture(entry->d_name, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
     		m_Textures[std::string(entry->d_name)] = tex_Id;
     		printf("Texture ID for %s is %d\n", entry->d_name, tex_Id);
		}
	}
}
uint TextureManager::getTexture(std::string name){
	return m_Textures[name];
}

TextureManager* TextureManager::m_pInstance = NULL;
