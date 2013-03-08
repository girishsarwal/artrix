#include "afx.h"

void RenderContext::initialize(int argc, char** argv){
	m_pTheContext = this;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	m_hWnd = glutCreateWindow("ARTRIX");
	glutDisplayFunc(RenderContext::loop);
	glutReshapeFunc(RenderContext::resize);
	glutIdleFunc(RenderContext::update);
}

void RenderContext::shutdown(){
	glutDestroyWindow(m_hWnd);
}

/** enter the main loop **/
void RenderContext::begin(){
	glutMainLoop();
	
}

void RenderContext::loop(){
	/** update the control sticks and other pots**/
	
	/** update the display **/
	glClear(GL_COLOR_BUFFER_BIT);
	m_pTheContext->m_pCurrentView->render();
	glutSwapBuffers();
}

void RenderContext::setup(){
	/** Set the startup view to the splash screen **/
	glClearColor(0.0f, 0.0f, 255.0f, 1.0f);
	m_pCurrentView = new SplashView();
	m_pCurrentView->create();
}

void RenderContext::update(){
	m_pTheContext->m_pCurrentView->update();
	glutPostRedisplay();
}

void RenderContext::resize(GLint w, GLint h){
	if(h ==0){
		h = 1;
	}
	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
}

RenderContext::RenderContext()
	: m_hWnd(NULL)
	, m_pCurrentView(NULL){
	
}

RenderContext::~RenderContext(){
}

RenderContext* RenderContext::m_pTheContext = NULL;
