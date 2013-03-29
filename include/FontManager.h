#pragma once
#include "afx.h"
class FontManager{
	private:
		int m_iNumTextures;
		static FontManager* m_pInstance;
		std::map<std::string, uint>	m_FontMaps;
		uint *m_arrFonts;
		FontManager();
	public:
		~FontManager();
		static FontManager* getInstance();
		void setActiveFont(std::string);
		void loadAllFonts(const char* fontRoot);
		void initialize();
		void shutdown();
};
