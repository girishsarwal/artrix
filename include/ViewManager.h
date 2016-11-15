/** View Manager

Loads a list of all views
Keeps  a list of views and return as necessary
**/

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <string>
#include "afx.h"
#include "KeyedManager.h"
#include "View.h"
#include "Widget.h"

class ViewManager{
private:
	std::string	mRoot;
	std::string mManifest;

	int m_iNumTextures;
	KeyedManager<View*>	 m_Views;
	//void processNode(xmlTextReaderPtr reader);
	View* m_pCurrentView;
	Widget* m_pCurrentWidget;
	static ViewManager* m_pTheViewManager;


public:
	void loadViewFromXml(char* pPath);
	int getNumWidgetsInView(View* pView);
	int getNumTextures();
	View* getView(std::string& sName);
	View* getCurrentView();
	void createStockViews();
	static ViewManager* getInstance();
	bool initialize(const std::string& root, const std::string& manifest);
	void shutdown();
	void changeView(View* view);
	ViewManager();
	~ViewManager();
};
#define VM ViewManager::getInstance()
#endif
