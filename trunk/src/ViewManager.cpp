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

View* ViewManager::getView(std::string& sName){
	printf("getting view");
	printf("%d", m_Views.getCount());
	int index = -1;
	while(++index < m_Views.getCount()){
		View* v = m_Views[index];
		printf("index is %d, view is %s", index, v->m_sName.c_str());
		if(sName == v->m_sName)
			return v;
	};
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
			AttributeSet asView;
			if(NULL != nodeView->properties){
				xmlAttr* attrView = NULL;
				for(attrView = nodeView->properties; attrView; attrView = attrView->next){
					const xmlChar* attrViewName = attrView->name;
					const xmlChar* attrViewValue = xmlGetProp(nodeView, attrViewName);
					printf("Attribute Found, %s=%s\n", attrViewName, attrViewValue);
					Attribute aView;
					aView.set(std::string((const char*)attrViewName), std::string((const char*)attrViewValue));
					asView.add(aView);
				}
			}
			View *v = new View();
			v->create(asView);
			for(xmlNode* nodeWidget = nodeView->children; nodeWidget; nodeWidget = nodeWidget->next){
				if(strcmp((char*)nodeWidget->name, "text") == 0) continue;
				AttributeSet asWidget;
				printf("Widget found, Type: %s\n", nodeWidget->name);
				if(NULL != nodeWidget->properties){
					xmlAttr* attrWidget = NULL;
					for(attrWidget = nodeWidget->properties; attrWidget; attrWidget = attrWidget->next){
						const xmlChar* attrWidgetName = attrWidget->name;
						const xmlChar* attrWidgetValue = xmlGetProp(nodeWidget, attrWidgetName);
						printf("Attribute Found, %s=%s\n", attrWidgetName, attrWidgetValue);
						Attribute aWidget;
						aWidget.set(std::string((const char*)attrWidgetName), std::string((const char*)attrWidgetValue));
						asWidget.add(aWidget);
					}
				}
				Widget *w = NULL;
				WidgetFactory::createWidget((char*)nodeWidget->name, &w, asWidget);
				v->addWidget(w);
			}
			m_Views.add(v);
		};
	}
	changeView(m_Views[0]);
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
void ViewManager::changeView(View* view){
	if(NULL != m_pCurrentView)
		m_pCurrentView->exit();
	m_pCurrentView = view;
	m_pCurrentView->enter();
}
ViewManager* ViewManager::m_pTheViewManager = NULL;
