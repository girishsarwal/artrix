#include "afx.h"
FontManager::FontManager(){
};

FontManager::~FontManager(){
};

FontManager* FontManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new FontManager();
	};
	return m_pInstance;
};

void FontManager::setActiveFont(std::string){
};

void FontManager::loadAllFonts(const char* fontRoot){
	/**read meta xml. If not found, assume each font to be 16x16**/ 

};

void FontManager::initialize(){
	loadAllFonts("/usr/share/artrix/fonts");
};

void FontManager::shutdown(){
};

FontManager* FontManager::m_pInstance = NULL;
