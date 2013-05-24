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

void BMFontManager::setActiveFont(std::string& font){

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
			m_uiCharCount = atoi((char*)xmlGetProp(nodeBMFont, (const xmlChar*)"count"));
			printf("No of characters %d\n", m_uiCharCount);
			m_uiFontLists = glGenLists(m_uiCharCount);
			for(xmlNode* nodeBMChar = nodeBMFont->children; nodeBMChar; nodeBMChar = nodeBMChar->next){
				if(NULL != nodeBMChar->properties){
					xmlAttr* attrChar = NULL;
					uint id;
					float x, y , width, height, xoffset, yoffset, xadvance;
					for(attrChar = nodeBMChar->properties; attrChar; attrChar = attrChar->next){
						if(strcmp((char*)attrChar->name, "id") == 0){
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
					}
					/** calculate the vertex and texture coordinate **/
						glNewList(id, GL_COMPILE);
						float mThis, mNext, nThis, nNext, halfHeight, halfWidth;
						mThis = (x/512.0);
						mNext = (x + width)/512.0;
						nThis = 1 - (y/512.0);
						nNext = 1 - ((y + height)/512.0);
						/*
						 * t--------r
						 * |		|
						 * |		|
						 * |		|
						 * l--------b
						*/
						halfHeight = height/10.0;
						halfWidth = width/10.0;
						printf("(%d is ", id);
						glBegin(GL_QUADS);
						{
							glTexCoord2f(mThis, nNext);				//BL
							glVertex2f(-halfWidth,-halfHeight);
							printf("%f, %f~", mThis, nNext);
				
							glTexCoord2f(mThis, nThis);				//TL
							glVertex2f(-halfWidth, halfHeight);
							printf("%f, %f~", mThis, nThis);
				
							glTexCoord2f(mNext,  nThis);			//TR
							glVertex2f( halfWidth, halfHeight);
							printf("%f, %f~", mNext, nThis);
				
							glTexCoord2f(mNext, nNext);				//BR
							glVertex2f( halfWidth,-halfHeight);
							printf("%f, %f", mNext, nNext);
						};
						printf(")\n");
						glEnd();
						glTranslatef(xadvance/5.0, 0, 0);
						glEndList();
				}
			}
		}
	}
	xmlFreeDoc(doc);
#else
	printf("Tree support not compiled");
#endif
	
};

void BMFontManager::shutdown(){
	glDeleteLists(m_uiFontLists, m_uiCharCount);
};

BMFontManager* BMFontManager::m_pInstance = NULL;
