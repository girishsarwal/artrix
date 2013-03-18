#include "afx.h"

int main(int argc, char* argv[]){
	if(NULL == RC) { printf("Cannot create RenderContext\n"); return false; }
	if(NULL == VM) { printf("Cannot create ViewManager\n"); return false; }
	
	VM->initialize();
	RC->initialize(argc, argv);
	TM->initialize();
	
	RC->setup();
	RC->begin();
	VM->shutdown();
	RC->shutdown();
	
	return 0;
};
