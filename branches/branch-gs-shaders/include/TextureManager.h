#pragma once
class TextureManager{
	private:
		int m_iNumTextures;
		static TextureManager* m_pInstance;
		std::map<std::string, uint>	m_Textures;
		uint *m_arrTextures;
	public:
		static TextureManager* getInstance();
		uint getTexture(std::string& texureName);
		void loadAllTextures(std::string& textureRoot);
		void loadTexture(std::string& texturePath);
		void useTexture(const std::string& textureName);
		void initialize();
};
