#include "afx.h"

void RenderContext::initialize(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(SCREEN_X_SIZE, SCREEN_Y_SIZE);
	m_hWnd = glutCreateWindow("ARTRIX");
	glutDisplayFunc(&(loop));
	glutReshapeFunc(&(resize));
	glutIdleFunc(&(update));
}

/** enter the main loop **/
void RenderContext::begin(){
	glutMainLoop();
}

void RenderContext::setup(){	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void RenderContext::shutdown(){
	glutDestroyWindow(m_hWnd);
}

RenderContext* RenderContext::getInstance(){
	if(NULL == m_pTheContext){
		m_pTheContext = new RenderContext();
	}
	return m_pTheContext;
}

RenderContext* RenderContext::m_pTheContext = NULL;

RenderContext::RenderContext()
	: m_hWnd(NULL)
	, m_pCurrentView(NULL){
	
}

RenderContext::~RenderContext(){
	
}
View* RenderContext::getCurrentView(){
	return m_pCurrentView;
}

void resize(GLint w, GLint h){
	if(h ==0){
		h = 1;
	}
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
}

void loop(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(NULL != VM->getCurrentView()){
		VM->getCurrentView()->render(0);		
	}
	glutSwapBuffers();
}

void update(){
	if(NULL != VM->getCurrentView()){
		VM->getCurrentView()->update(0);		
	}
	glutPostRedisplay();
}
