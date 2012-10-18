#include "afx.h"
void loop();
void setup();
void update();
void resize(GLint w, GLint h);
View* pCurrentView = NULL;

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	int hWnd = glutCreateWindow("ARTIX");
	glutDisplayFunc(loop);
	glutReshapeFunc(resize);
	glutIdleFunc(update);
	setup();
	glutMainLoop();
	glutDestroyWindow(hWnd);
	return 0;
}
void resize(GLint w, GLint h){
	if(h ==0){
		h = 1;
	}
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, w, h);
	glOrtho(-100, 100, -100, 100, -100, 100);
}

void setup(){
	/** Set the startup view to the splash screen **/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	pCurrentView = new SplashView();

};
void loop(){
	/** update the control sticks and other pots**/
	
	/** update the display **/
	glClear(GL_COLOR_BUFFER_BIT);
	pCurrentView->update();
	glutSwapBuffers();
};
void update(){
};

