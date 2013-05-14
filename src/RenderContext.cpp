#include "afx.h"

void RenderContext::initialize(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_X_SIZE, SCREEN_Y_SIZE);
	m_hWnd = glutCreateWindow("ARTRIX");
	glutDisplayFunc(&(loop));
	glutReshapeFunc(&(resize));
	glutIdleFunc(&(update));
}

/** enter the main loop **/
void RenderContext::begin(){
	clock_getres(CLOCK_PROCESS_CPUTIME_ID, &tvClockResolution);
	printf("Clock Resolution is %ldns\n", tvClockResolution.tv_nsec);
	clock_gettime(CLOCK_REALTIME, &tvLastTime);
	
	//gettimeofday(&tvLastTime, 0);
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
	
	memset(&tvLastTime, 0, sizeof(timeval));
	memset(&tvCurrentTime, 0, sizeof(timeval));
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
	clock_gettime(CLOCK_MONOTONIC, &tvCurrentTime);
	//gettimeofday(&tvCurrentTime, 0);
	dElapsedTime = tvCurrentTime.tv_nsec - tvLastTime.tv_nsec;
	tvLastTime = tvCurrentTime; 
	if(NULL != VM->getCurrentView()){
		VM->getCurrentView()->render(dElapsedTime);		
	}
	printf("time %f", (double) dElapsedTime);
	glutSwapBuffers();
}

void update(){
	if(NULL != VM->getCurrentView()){
		VM->getCurrentView()->update(dElapsedTime);		
	}
	glutPostRedisplay();
}
