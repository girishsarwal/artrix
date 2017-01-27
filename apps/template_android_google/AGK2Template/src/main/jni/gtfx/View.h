#ifndef VIEW_H
#define VIEW_H
#include "afx.h"
#include "KeyManageable.h"
namespace gtfx {
class GameObject;
class View
	: public KeyManageable
{
public:
	vector<gtfx::GameObject*> mWidgets;
	View();
	View(tinyxml2::XMLNode*);

	virtual ~View(void);

	void Update(double frameTime);
	void AddWidget(gtfx::GameObject* pWidget);
	void initialize();
	
protected:
	
	virtual void onInitialize();
	virtual void onUpdate(double frameTime);
};
}
#endif
