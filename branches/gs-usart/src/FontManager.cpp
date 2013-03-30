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
	printf("Active Fonr %d", TM->getTexture(font));
	
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
	
	createFontDisplayList(m_uiSmallFont, 10);
	createFontDisplayList(m_uiMediumFont, 12);
	createFontDisplayList(m_uiLargeFont, 16);
};
void FontManager::createFontDisplayList(uint base, int size){
	int index = -1;
	
	while(++index < FONT_MAX_CHARS)
	{
		glNewList(base + index, GL_COMPILE);
		float cy = (index % FONT_TEXTURE_COLS) / (FONT_TEXTURE_ROWS * 1.0);
		float cx  = (index / FONT_TEXTURE_ROWS)/ (FONT_TEXTURE_ROWS * 1.0);
		printf("%f-%f\n", cx, cy);
		glBegin(GL_QUADS);
			{
				glTexCoord2f(cx, cy);
				glVertex2f(-size,-size);
				glTexCoord2f(cx, cy + 0.0625);
				glVertex2f(-size, size);
				glTexCoord2f(cx + 0.0625, cy + 0.0625);
				glVertex2f( size, size);
				glTexCoord2f(cx + 0.0625, cy);
				glVertex2f( size,-size);
				/*glTexCoord2f(0, 0);
				glVertex2f(-25,-25);
				glTexCoord2f(0, 1);
				glVertex2f(-25, 25);
				glTexCoord2f(1, 1);
				glVertex2f( 25, 25);
				glTexCoord2f(1, 0);
				glVertex2f( 25,-25);*/
			};
		glEnd();
		glTranslatef((1.5 *size), 0, 0);
		glEndList();
	};
};

void FontManager::shutdown(){
	glDeleteLists(m_uiSmallFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiMediumFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiLargeFont, FONT_MAX_CHARS);
};

FontManager* FontManager::m_pInstance = NULL;
