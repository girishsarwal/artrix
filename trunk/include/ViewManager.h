/** View Manager
Loads a list of all views
Keeps  a list of views and return as necessary
**/
#include "afx.h"
class ViewManager{
private:
	int m_iNumTextures;

public:
	void loadViewFromXml(char* pPath);
	int getNumWidgetsInView(View* pView);
	int getNumTextures();
	View* getView(char* pName);
	void createStockViews();
};
