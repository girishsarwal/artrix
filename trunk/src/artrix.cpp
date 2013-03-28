#include "afx.h"

int main(int argc, char* argv[]){
	if(NULL == RC) { printf("ERROR: Cannot create RenderContext\n"); return false; }
	if(NULL == VM) { printf("ERROR: Cannot create ViewManager\n"); return false; }
	if(NULL == SI) { printf("WARNING: Cannot create SerialInterface"); return false; }
	
	VM->initialize();
	RC->initialize(argc, argv);
	TM->initialize();
	SI->initialize();
	
	RC->setup();
	RC->begin();
	
	VM->shutdown();
	RC->shutdown();
	SI->shutdown();
	return 0;
};
