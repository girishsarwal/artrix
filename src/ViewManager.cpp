/** View Manager
Loads a list of all views
Keeps  a list of views and return as necessary
**/
#include "ViewManager.h"

ViewManager::ViewManager(){
	//m_Views.clear();
};

ViewManager::~ViewManager(){
};

bool ViewManager::initialize(const std::string& root, const std::string& manifest){
	mRoot = root;
	mManifest = manifest;

	printf("\n+--------------------VIEW MANAGER----------------------+\n");
	printf("\nInitializing from %s", mRoot.c_str());
	CreateStockViews();
	return true;
};
void ViewManager::shutdown(){

};

ViewManager* ViewManager::getInstance(){
	if(!m_pTheViewManager){
		m_pTheViewManager = new ViewManager();
	}
	return m_pTheViewManager;
};

void ViewManager::SetCurrentView(View* view){
	if(NULL == view){
		return;
	}
	printf("\nSetting %s as active", view->GetName().c_str());
	mCurrentView = view;
}

View* ViewManager::GetCurrentView(){
	return mCurrentView;
}


bool ViewManager::CreateStockViews(){
	std::string manifest = mRoot+ "/" + mManifest;
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError result = doc.LoadFile(manifest.c_str());
	if(result != tinyxml2::XML_SUCCESS){
		printf("\ncannot open manifest %s", manifest.c_str());
		return false;
	}

	for (tinyxml2::XMLNode *screenNode = doc.RootElement()->FirstChild(); screenNode; screenNode = screenNode->NextSibling()) {
		View* view = new View(screenNode);
		for(tinyxml2::XMLNode *widgetNode = screenNode->FirstChild(); widgetNode; widgetNode= widgetNode->NextSibling()) {
			Widget* w = NULL;
			WidgetFactory::CreateWidget(widgetNode, &w);
			view->AddWidget(w);
		}
		if(screenNode->ToElement()->Attribute("default") != NULL) SetCurrentView(view);
	}
	return true;
};

void ViewManager::ChangeView(View* view){

};


ViewManager* ViewManager::m_pTheViewManager = NULL;



