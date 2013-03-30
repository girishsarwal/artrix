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
View* ViewManager::getCurrentView(){
	return m_pCurrentView;
}
void ViewManager::createStockViews(){
#ifdef LIBXML_TREE_ENABLED
	xmlDoc* doc = NULL;
	
	doc = xmlReadFile("/usr/share/artrix/screens/screens.xml", NULL, 0);
	
	for(xmlNode* nodeView = xmlDocGetRootElement(doc)->children; nodeView; nodeView = nodeView->next){
		if(strcmp((char*)nodeView->name, "text") == 0) continue;
		if(strcmp((char*)nodeView->name, "view") == 0){
			printf("View Found\n");
			View *v = new View();
			for(xmlNode* nodeWidget = nodeView->children; nodeWidget; nodeWidget = nodeWidget->next){
				if(strcmp((char*)nodeWidget->name, "text") == 0) continue;
				printf("Widget found, Type: %s\n", nodeWidget->name);
				AttributeSet as;
				if(NULL != nodeWidget->properties){
					xmlAttr* attrWidget = NULL;
					for(attrWidget = nodeWidget->properties; attrWidget; attrWidget = attrWidget->next){
						const xmlChar* name = attrWidget->name;
						const xmlChar* value = xmlGetProp(nodeWidget, name);
						printf("Attribute Found, %s=%s\n", name, value);
						Attribute a;
						a.set(std::string((const char*)name), std::string((const char*)value));
						as.add(a);
					}
				}
				Widget *w = NULL;
				WidgetFactory::createWidget((char*)nodeWidget->name, &w, as);
				v->addWidget(w);
			}
			m_Views.add(v);
		};
	}
	m_pCurrentView = m_Views.getAtIndex(0);
	xmlFreeDoc(doc);
#else
	printf("Tree support not compiled");
#endif
	
}
void ViewManager::initialize(){
	createStockViews();
}
void ViewManager::shutdown(){
	
}
ViewManager::ViewManager(){
	m_Views.clear();
};

ViewManager::~ViewManager(){
}

ViewManager* ViewManager::getInstance(){
	if(NULL == m_pTheViewManager){
		m_pTheViewManager = new ViewManager();
	}
	return m_pTheViewManager;
}

ViewManager* ViewManager::m_pTheViewManager = NULL;
