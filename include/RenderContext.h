#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#define SCREEN_UNIT_X 100
#define SCREEN_UNIT_Y 100

#include "afx.h"
#include "View.h"
#include "ViewManager.h"
#include "Geometry.h"

class RenderContext{
private:
	int m_hWnd;
	View* m_pCurrentView;
	static RenderContext* m_pTheContext;
	RenderContext();

public:
	bool initialize(int argc, char** argv);
	void setup();
	void begin();
	void shutdown();
	View* getCurrentView();
	static RenderContext* getInstance();
	~RenderContext();
	void showVersionInformation();
};

extern "C" void loop();
extern "C" void update();
extern "C" void resize(GLint w, GLint h);

#define RC RenderContext::getInstance()
#endif
