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
	while(NULL != (entry = readdir(dir))){
		if(entry->d_type != DT_DIR){
			m_iNumTextures++;
		}
	}
	closedir(dir);
	printf("Number of textures found: %d\n", m_iNumTextures);
	m_arrTextures = (uint*) malloc(m_iNumTextures * sizeof(uint));
	glGenTextures(m_iNumTextures, m_arrTextures);
	dir = opendir(textureRoot);
	if(NULL == dir){
		printf("Error opening texture directory '%s'\n", textureRoot);
		return;
	}
	int index = -1;
	while(NULL != (entry = readdir(dir))){
		if(entry->d_type != DT_DIR){
			FILE* fp = NULL;long lSize;
			chdir(textureRoot);
			fp = fopen(entry->d_name, "rb");
			if(NULL == fp){
				printf("Cannot open texture file '%s'\n", entry->d_name);
				continue;
			}
			char* pBuffer = NULL;
			size_t result = 0;

			fseek(fp, 0, SEEK_END);
			lSize = ftell(fp);
			rewind(fp);

			pBuffer = (char*)malloc(lSize * sizeof(char));
			result = fread(pBuffer, 1, lSize, fp);
			fclose(fp);
			
			printf("Texture Read, %ld bytes\n", lSize);
			glBindTexture(GL_TEXTURE_2D, m_arrTextures[++index]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, pBuffer);

			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			
     		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
     		
     		m_Textures[std::string(entry->d_name)] = m_arrTextures[index];
     		printf("Texture ID for %s is %d", entry->d_name, m_Textures[entry->d_name]);
     		
			delete pBuffer;
		}
	}
}
uint TextureManager::getTexture(std::string name){
	return m_Textures[name];
}


TextureManager* TextureManager::m_pInstance = NULL;
