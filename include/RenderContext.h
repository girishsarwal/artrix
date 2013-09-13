#pragma once
#include "afx.h"
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
};

extern "C" void loop();
extern "C" void update();
extern "C" void resize(GLint w, GLint h);

