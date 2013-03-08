#pragma once
#include "afx.h"
class RenderContext{
private:
	int m_hWnd;
	View* m_pCurrentView;
	static RenderContext* m_pTheContext;
public:
	void initialize(int argc, char** argv);
	void setup();
	void shutdown();
	void begin();

	RenderContext();
	~RenderContext();

	static void loop();
	
	static void update();
	static void resize(GLint w, GLint h);
	
};
