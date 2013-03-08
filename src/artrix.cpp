#include "afx.h"
void loop();
void setup();
void update();
void resize(GLint w, GLint h);

RenderContext* rc = NULL;

int main(int argc, char* argv[]){
	rc = new RenderContext();
	rc->initialize(argc, argv);
	rc->setup();
	rc->begin();
	rc->shutdown();
	return 0;
}



