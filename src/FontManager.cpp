#include "afx.h"
FontManager::FontManager(){
};

FontManager::~FontManager(){
};

FontManager* FontManager::getInstance(){
	if(!m_pInstance){
		m_pInstance = new FontManager();
	};
	return m_pInstance;
};

void FontManager::setActiveFont(std::string& font, std::string& size){
	setActiveFont(font, size, false);
};

void FontManager::setActiveFont(std::string& font, std::string& size, bool bold){
	glBindTexture(GL_TEXTURE_2D, TM->getTexture(font));
	if(size == SMALL_TEXT){
		m_uiActiveListBase = m_uiSmallFont;
	}
	else if(size == MEDIUM_TEXT){
		m_uiActiveListBase = m_uiMediumFont;
	}
	else if (size == LARGE_TEXT){
		m_uiActiveListBase = m_uiLargeFont;
	};
	if(bold){
		glListBase(m_uiActiveListBase - 32);
	} else
	glListBase(m_uiActiveListBase + 96);
	
};
uint FontManager::getActiveFontBase(){
	printf("ACTIVE LIST BASE IS ---------- %d", m_uiActiveListBase);
	return m_uiActiveListBase;
};

void FontManager::initialize(){
	/**create the display lists for ASCII 256 font **/
	m_uiSmallFont = glGenLists(FONT_MAX_CHARS);
	m_uiMediumFont = glGenLists(FONT_MAX_CHARS);
	m_uiLargeFont = glGenLists(FONT_MAX_CHARS);
	createFontDisplayList(m_uiSmallFont, 4);
	createFontDisplayList(m_uiMediumFont, 6);
	createFontDisplayList(m_uiLargeFont, 8);
};
void FontManager::createFontDisplayList(uint base, int size){
	float m = 0;
	float n = 0;
	
	

	float cx = 1.0/FONT_TEXTURE_COLS;
	float cy = 1.0/FONT_TEXTURE_ROWS;
	
	int index = -1;
	
	while(++index < FONT_MAX_CHARS)
	{
		glNewList(base + index, GL_COMPILE);
		m = (index % FONT_TEXTURE_COLS);
		n  = (index / FONT_TEXTURE_ROWS);
		
		float mThis = m * cx;
		float nThis = 1 - (n * cy);
		float mNext = (m + 1) * cx;
		float nNext = 1 - ((n + 1) * cy);
		float halfSize = size / 2.0;
		
		glBegin(GL_QUADS);
			{
				glTexCoord2f(mThis, nNext);
				glVertex2f(-halfSize,-halfSize);
				
				glTexCoord2f(mThis, nThis);
				glVertex2f(-halfSize, halfSize);
				
				glTexCoord2f(mNext,  nThis);				
				glVertex2f( halfSize, halfSize);
				
				glTexCoord2f(mNext, nNext);
				glVertex2f( halfSize,-halfSize);
			};
		glEnd();
		glTranslatef(size * 0.8, 0, 0);
		glEndList();
	};
};

void FontManager::shutdown(){
	glDeleteLists(m_uiSmallFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiMediumFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiLargeFont, FONT_MAX_CHARS);
};

FontManager* FontManager::m_pInstance = NULL;
