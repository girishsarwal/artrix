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

void ViewManager::createStockViews(){
	/** load up default xml and create all views **/
	XmlTextReaderPtr reader;
	reader = new XmlNewTextReaderFileName("screens/screens.xml");
	
	
}
