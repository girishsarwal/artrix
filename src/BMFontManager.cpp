#include "afx.h"
BMFontManager::BMFontManager(){
};

BMFontManager::~BMFontManager(){
};

BMFontManager* BMFontManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new BMFontManager();
	};
	return m_pInstance;
};

void BMFontManager::setActiveFont(std::string& font, std::string& size){
	/*setActiveFont(font, size, false);*/
};

void BMFontManager::setActiveFont(std::string& font, std::string& size, bool bold){
	/*glBindTexture(GL_TEXTURE_2D, TM->getTexture(font));
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
	*/
};
uint BMFontManager::getActiveFontBase(){
	printf("ACTIVE LIST BASE IS ---------- %d", m_uiActiveListBase);
	return m_uiActiveListBase;
};

void BMFontManager::initialize(){	
	/** read up all fonts in the font directory **/
	std::string fontRoot(FONTROOT);
	printf("Loading fonts\n");
	DIR* dir;
	dirent* entry;
	dir = opendir(fontRoot.c_str());
	if(NULL == dir){
		printf("Error opening font directory '%s'\n", fontRoot.c_str());
		return;
	}
	chdir(fontRoot.c_str());
	while(NULL != (entry = readdir(dir))){
		if(entry->d_type != DT_DIR){
			std::string fontName = std::string(entry->d_name);
			createFontDisplayListFromBMFont(fontName);
			printf("Found font %s\n", fontName.c_str());
		}
	}
	
	/**create the display lists for ASCII 256 font **/
	
	
	
	/*m_uiSmallFont = glGenLists(FONT_MAX_CHARS);
	m_uiMediumFont = glGenLists(FONT_MAX_CHARS);
	m_uiLargeFont = glGenLists(FONT_MAX_CHARS);

	createFontDisplayList(m_uiSmallFont, 4);
	createFontDisplayList(m_uiMediumFont, 6);
	createFontDisplayList(m_uiLargeFont, 8);*/
};

void BMFontManager::createFontDisplayListFromBMFont(std::string& fontFile){
	/** generate display lists **/
#ifdef LIBXML_TREE_ENABLED
	xmlDoc* doc = NULL;
	chdir(FONTROOT);
	doc = xmlReadFile(fontFile.c_str(), NULL, 0);
	
	for(xmlNode* nodeBMFont = xmlDocGetRootElement(doc)->children; nodeBMFont; nodeBMFont = nodeBMFont->next){
		if(strcmp((char*)nodeBMFont->name, "text") == 0) continue;
		if(strcmp((char*)nodeBMFont->name, "pages") == 0) continue;
		if(strcmp((char*)nodeBMFont->name, "info") == 0){
			/** build the basic detauls of the BMFont **/
		}
		else if(strcmp((char*)nodeBMFont->name, "common") == 0){
		}
		else if(strcmp((char*)nodeBMFont->name, "chars") == 0){
			int numberOfChars = atoi((char*)xmlGetProp(nodeBMFont, (const xmlChar*)"count"));
			printf("No of characters %d\n", numberOfChars);
			m_uiSmallFont = glGenLists(numberOfChars);
			m_uiMediumFont = glGenLists(numberOfChars);
			m_uiLargeFont = glGenLists(numberOfChars);
			for(xmlNode* nodeBMChar = nodeBMFont->children; nodeBMChar; nodeBMChar = nodeBMChar->next){
				if(NULL != nodeBMChar->properties){
					xmlAttr* attrChar = NULL;
					for(attrChar = nodeBMChar->properties; attrChar; attrChar = attrChar->next){
						uint id;
						float x, y , width, height, xoffset, yoffset, xadvance;
						if(strcmp((char*)attrChar->name, "x") == 0){
							id = atoi((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						else if(strcmp((char*)attrChar->name, "x") == 0){
							x = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						} 
						else if(strcmp((char*)attrChar->name, "y") == 0){
							y = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						else if(strcmp((char*)attrChar->name, "width") == 0){
							width = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						else if(strcmp((char*)attrChar->name, "height") == 0){
							height = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						else if(strcmp((char*)attrChar->name, "xoffset") == 0){
							xoffset = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						else if(strcmp((char*)attrChar->name, "yoffset") == 0){
							yoffset = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						else if(strcmp((char*)attrChar->name, "xadvance") == 0){
							xadvance = atof((const char*)xmlGetProp(nodeBMChar, attrChar->name));
						}
						/** calculate the vertex and texture coordinate **/
						glNewList(id, GL_COMPILE);
						glBegin(GL_QUADS);
						{
						};
						glEnd();
						glTranslatef(xadvance, 0, 0);
						glEndList();
					}
				}
			}
		}
	}
	xmlFreeDoc(doc);
#else
	printf("Tree support not compiled");
#endif
	
}
void BMFontManager::createFontDisplayList(uint base, int size){
/*	float m = 0;
	float n = 0;
	
	float mThis = 0.0;
	float nThis = 0.0;
	float mNext = 0.0;
	float nNext = 0.0;
	
	float cx = 1.0/FONT_TEXTURE_COLS;
	float cy = 1.0/FONT_TEXTURE_ROWS;
	float halfSize = size / 2.0;
	
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
	* */
};

void BMFontManager::shutdown(){
	/*glDeleteLists(m_uiSmallFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiMediumFont, FONT_MAX_CHARS);
	glDeleteLists(m_uiLargeFont, FONT_MAX_CHARS);
	* */
};

BMFontManager* BMFontManager::m_pInstance = NULL;
