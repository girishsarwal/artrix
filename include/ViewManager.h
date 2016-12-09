/** View Manager

Loads a list of all views
Keeps  a list of views and return as necessary
**/

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

class View;
class GameObject;

#include <string>
#include "afx.h"
#include "KeyedManager.h"
#include "View.h"
#include "GameObject.h"

class ViewManager:
	public KeyedManager<View*> {
private:
	std::string	mRoot;
	std::string mManifest;

	View* mCurrentView;

	static ViewManager* m_pTheViewManager;

	bool CreateStockViews();
	void SetCurrentView(View*);

public:
	View* GetCurrentView();
	void ChangeView(const std::string&);

	static ViewManager* getInstance();
	bool initialize(const std::string& root, const std::string& manifest);
	void shutdown();

	ViewManager();
	~ViewManager();
};
#define VM ViewManager::getInstance()
#endif
