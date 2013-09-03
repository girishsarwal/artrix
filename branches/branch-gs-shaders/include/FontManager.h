#pragma once
#include "afx.h"
#define FONT_TEXTURE_ROWS 16
#define FONT_TEXTURE_COLS 16
#define FONT_MAX_CHARS FONT_TEXTURE_ROWS * FONT_TEXTURE_COLS
#define SMALL_TEXT std::string("small")
#define MEDIUM_TEXT std::string("medium")
#define LARGE_TEXT std::string("large")
class FontManager{
	private:
		int m_iNumTextures;
		static FontManager* m_pInstance;
		uint m_uiSmallFont;
		uint m_uiMediumFont;
		uint m_uiLargeFont;
		uint m_uiActiveListBase;
		FontManager();
		void createFontDisplayList(uint base, int size);
	public:
		~FontManager();
		static FontManager* getInstance();
		void setActiveFont(std::string& font, std::string& size);
		void setActiveFont(std::string& font, std::string& size, bool bold);
		uint getActiveFontBase();
		void initialize();
		void shutdown();
};
