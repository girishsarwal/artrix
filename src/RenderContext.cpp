#include "RenderContext.h"
static timespec tvLastTime;
static timespec tvCurrentTime;
static long int dElapsedTime;

bool RenderContext::initialize(int argc, char** argv){
	printf("\n+--------------------RENDER CONTEXT----------------------+\n");
	printf("Initializing...\n");

	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 800, 600, "ARTRIX", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, resize);
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	showVersionInformation();
	return true;
}

/** enter the main loop **/
void RenderContext::begin(){
	printf("\n+--------------------GAME LOOP BEGIN----------------------+\n");
	clock_gettime(CLOCK_REALTIME, &tvLastTime);
	printf("Starting from clock %li\n", tvLastTime.tv_sec);

	do{
		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
		clock_gettime(CLOCK_REALTIME, &tvCurrentTime);
		dElapsedTime = ((tvCurrentTime.tv_sec - tvLastTime.tv_sec) * 1000)  + (tvCurrentTime.tv_nsec - tvLastTime.tv_nsec)/ 1000000;
		tvLastTime = tvCurrentTime;
		frame();
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );
}


void RenderContext::frame() {
	if(NULL != VM->GetCurrentView()){
		View* v =VM->GetCurrentView();
		v->Update(dElapsedTime);
	}
}


void RenderContext::shutdown(){
	//glutDestroyWindow(m_hWnd);
}

RenderContext* RenderContext::getInstance(){
	if(!m_pTheContext){
		m_pTheContext = new RenderContext();
	}
	return m_pTheContext;
}

RenderContext* RenderContext::m_pTheContext = NULL;

RenderContext::RenderContext()
	: m_pCurrentView(NULL){
	
	memset(&tvLastTime, 0, sizeof(timeval));
	memset(&tvCurrentTime, 0, sizeof(timeval));
}

RenderContext::~RenderContext(){
	
}
View* RenderContext::getCurrentView(){
	return m_pCurrentView;
}

void resize(GLFWwindow* window, GLint w, GLint h){
	if(h ==0){
		h = 1;
	}
	glViewport(0, 0, w, h);
}


void RenderContext::showVersionInformation(){
	printf("GL Information \n");
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
	printf("Shader Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
};




