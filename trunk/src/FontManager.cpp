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

void FontManager::setActiveFont(std::string& font, std::string& size){
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
};
uint FontManager::getActiveFontBase(){
	return m_uiActiveListBase;
};

void FontManager::initialize(){
	/**create the display lists for ASCII 256 font **/
	m_uiSmallFont = glGenLists(FONT_MAX_CHARS);
	m_uiMediumFont = glGenLists(FONT_MAX_CHARS);
	m_uiLargeFont = glGenLists(FONT_MAX_CHARS);
	createFontDisplayList(m_uiSmallFont, 4);
	createFontDisplayList(m_uiMediumFont, 8);
	createFontDisplayList(m_uiLargeFont, 12);
};
void FontManager::createFontDisplayList(uint base, int size){
	float m = 0;
	float n = 0;
	
	float mThis = 0.0;
	float nThis = 0.0;
	float mNext = 0.0;
	float nNext = 0.0;
	
	float cx = 1.0/FONT_TEXTURE_COLS;
	float cy = 1.0/FONT_TEXTURE_ROWS;
	float halfSize = size / 2.0;
	
	printf("Params %f, %f, %f, %f", m, n, cx, cy);
	
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
		
		printf("coordinate %f, %f\n", m, n);
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
		glTranslatef(size, 0, 0);
		glEndList();
	};
};

void FontManager::shutdown(){
	glDeleteLists(m_uiSmallFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiMediumFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiLargeFont, FONT_MAX_CHARS);
};

FontManager* FontManager::m_pInstance = NULL;
