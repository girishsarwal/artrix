#pragma once
class TextureManager{
	private:
		int m_iNumTextures;
		static TextureManager* m_pInstance;
		std::map<std::string, uint>	m_Textures;
		uint *m_arrTextures;
		std::string m_root;
	public:
		static TextureManager* getInstance();
		uint getTexture(std::string& texureName);
		void loadAllTextures();
		void loadTexture(std::string& texturePath);
		void useTexture(const std::string& textureName);
		void initialize(const std::string& root);
};
