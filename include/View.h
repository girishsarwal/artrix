#pragma once
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "afx.h"
#include "KeyManageable.h"
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

