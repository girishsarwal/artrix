#include "RenderContext.h"
static timespec tvLastTime;
static timespec tvCurrentTime;
static long int dElapsedTime;

bool RenderContext::initialize(int argc, char** argv){
	printf("\n+--------------------RENDER CONTEXT----------------------+\n");
	printf("Initializing...\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_X_SIZE, SCREEN_Y_SIZE);
	if (!glutGet(GLUT_DISPLAY_MODE_POSSIBLE)) // HACK: From glxGears
	      exit(1);
	m_hWnd = glutCreateWindow("ARTRIX");
	glewInit();
	glutDisplayFunc(&(loop));
	glutReshapeFunc(&(resize));
	glutIdleFunc(&(update));
	showVersionInformation();
	return true;
}

/** enter the main loop **/
void RenderContext::begin(){
	clock_gettime(CLOCK_REALTIME, &tvLastTime);
	glutMainLoop();
}

void RenderContext::setup(){	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}


void RenderContext::shutdown(){
	glutDestroyWindow(m_hWnd);
}

RenderContext* RenderContext::getInstance(){
	if(!m_pTheContext){
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
	glOrtho(-SCREEN_UNIT_X, SCREEN_UNIT_X, -SCREEN_UNIT_Y, SCREEN_UNIT_Y, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void loop(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	clock_gettime(CLOCK_REALTIME, &tvCurrentTime);
	dElapsedTime = ((tvCurrentTime.tv_sec - tvLastTime.tv_sec) * 1000)  + (tvCurrentTime.tv_nsec - tvLastTime.tv_nsec)/ 1000000;
	tvLastTime = tvCurrentTime; 
	update();
	glutSwapBuffers();
}

void update(){
	if(NULL != VM->GetCurrentView()){
		VM->GetCurrentView()->Update(dElapsedTime);
	}
	glutPostRedisplay();
}

void RenderContext::showVersionInformation(){
	printf("GL Information \n");
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
	printf("Shader Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
};
