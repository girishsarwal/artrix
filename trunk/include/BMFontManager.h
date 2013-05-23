#pragma once
#include "afx.h"
//#define SMALL_TEXT std::string("small")
//#define MEDIUM_TEXT std::string("medium")
//#define LARGE_TEXT std::string("large")
#define FONTROOT "/usr/share/artrix/fonts"
class BMFontManager{
	private:
		int m_iNumTextures;
		static BMFontManager* m_pInstance;
		std::map<std::string, uint>	m_Textures;
		uint m_uiSmallFont;
		uint m_uiMediumFont;
		uint m_uiLargeFont;
		uint m_uiActiveListBase;
		BMFontManager();
		void createFontDisplayList(uint base, int size);
		void createFontDisplayListFromBMFont(std::string&);
	public:
		~BMFontManager();
		static BMFontManager* getInstance();
		void setActiveFont(std::string& font, std::string& size);
		void setActiveFont(std::string& font, std::string& size, bool bold);
		uint getActiveFontBase();
		void initialize();
		void shutdown();
};
