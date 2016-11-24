#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#define SCREEN_UNIT_X 1
#define SCREEN_UNIT_Y 1

#include "afx.h"
#include "View.h"
#include "ViewManager.h"
#include "Geometry.h"

class RenderContext{
private:
	GLFWwindow* window;
	View* m_pCurrentView;
	static RenderContext* m_pTheContext;
	RenderContext();


	GLuint VertexArrayID;

	GLuint vertexbuffer;
public:
	bool initialize(int argc, char** argv);
	void setup();
	void begin();
	void frame();
	void shutdown();
	View* getCurrentView();
	static RenderContext* getInstance();
	~RenderContext();
	void showVersionInformation();
};




#define RC RenderContext::getInstance()
#endif
