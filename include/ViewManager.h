/** View Manager
Loads a list of all views
Keeps  a list of views and return as necessary
**/
#include "afx.h"
class ViewManager{
private:
	int m_iNumTextures;
	SharedAllocation<View*> m_Views;
	void processNode(xmlTextReaderPtr reader);
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
	void initialize();
	void shutdown();
	void changeView(View* view);
	ViewManager();
	~ViewManager();
};

