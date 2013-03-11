/** View Manager
Loads a list of all views
Keeps  a list of views and return as necessary
**/
#include "afx.h"
void ViewManager::loadViewFromXml(char* pPath){
}

int ViewManager::getNumWidgetsInView(View* pView){
	return 0;
}

int ViewManager::getNumTextures(){
	return m_iNumTextures;
}

View* ViewManager::getView(char* pName){
	return NULL;
}
void ViewManager::processNode(xmlTextReaderPtr reader){
	int nodeType = xmlTextReaderNodeType(reader);
	xmlChar* nodeName = xmlTextReaderName(reader);
	printf("Found: NodeType:%d NodeName:%s\n", nodeType , nodeName);
	switch(xmlTextReaderNodeType(reader)){
		case 1:		/** something has started **/
			if(strcmp((char*)nodeName, "views") == 0) break;
			if(strcmp((char*)nodeName, "view") == 0){
				printf("Found view node. Creating new View\n");
				m_pCurrentView = new View();
				break;
			}
			/**widget coming in, create **/
			Widget* w;
			WidgetFactory::createWidget((char*)nodeName, w);
			break;
		case 15:
			if(strcmp((char*)nodeName, "view") == 0){
				printf("Finalizing view\n");
				m_Views.add(m_pCurrentView);
			}
			break;
	}
};
void ViewManager::createStockViews(){
	printf("Reading Stock Views\n");
	xmlTextReaderPtr reader = NULL;
	reader = xmlNewTextReaderFilename("/usr/share/artrix/screens/screens.xml");
	int ret = 0;
	if(reader == NULL){
		printf("Could not load default views. No views will be available \n");
		return;
	}
	ret = xmlTextReaderRead(reader);
	while(ret == 1)
	{
		processNode(reader);
		ret = xmlTextReaderRead(reader);
	}
	xmlFreeTextReader(reader);
}
