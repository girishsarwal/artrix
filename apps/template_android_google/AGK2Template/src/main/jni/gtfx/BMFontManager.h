#ifndef BMFONTMANAGER_H
#define BMFONTMANAGER_H
#include "afx.h"
#define SMALL_TEXT std::string("small")
#define MEDIUM_TEXT std::string("medium")
#define LARGE_TEXT std::string("large")
namespace gtfx {
class BMFontManager{
	private:
		std::string mRoot;
		std::string mManifest;
		static BMFontManager* m_pInstance;
		BMFontManager();
		uint m_uiFontLists;
		uint m_uiCharCount;
		void createFontDisplayListFromBMFont(std::string&);
	public:
		~BMFontManager();
		static BMFontManager* GetInstance();
		void setActiveFont(std::string& font);
		bool initialize(const std::string& root, const std::string& manifest);
		void shutdown();
};
}
#endif

