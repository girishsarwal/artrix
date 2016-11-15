#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "afx.h"
#include "Texture.h"
#include "KeyedManager.h"
class TextureManager:
	public KeyedManager<Texture*> {
private:
	int m_iNumTextures;
	static TextureManager* m_pInstance;
	std::map<std::string, uint>	m_Textures;
	uint *m_arrTextures;
	std::string mRoot;
	std::string mManifest;
public:
	static TextureManager* getInstance();
	bool loadAllTextures();
	bool initialize(const std::string& root,const std::string& manifest);
};
#define TM TextureManager::getInstance()
#endif
