#pragma once
#include "afx.h"
//#define SMALL_TEXT std::string("small")
//#define MEDIUM_TEXT std::string("medium")
//#define LARGE_TEXT std::string("large")
#define FONTROOT "/usr/share/artrix/fonts"
class BMFontManager{
	private:
		std::string mRoot;
		static BMFontManager* m_pInstance;
		BMFontManager();
		uint m_uiFontLists;
		uint m_uiCharCount;
		void createFontDisplayListFromBMFont(std::string&);
	public:
		~BMFontManager();
		static BMFontManager* getInstance();
		void setActiveFont(std::string& font);
		bool initialize(const string& root);
		void shutdown();
};
