#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include "afx.h"
#include "View.h"
#include "ViewManager.h"
#include "Geometry.h"
namespace gtfx {
class View;
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
	View* GetCurrentView();
	static RenderContext* GetInstance();
	~RenderContext();
	void showVersionInformation();
};
extern "C" void resize(GLFWwindow*, int, int);

}

#endif
