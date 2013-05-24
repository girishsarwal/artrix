#include "afx.h"

int main(int argc, char* argv[]){
	if(NULL == RC) { printf("ERROR: Cannot create RenderContext\n"); return false; }
	if(NULL == VM) { printf("ERROR: Cannot create ViewManager\n"); return false; }
	if(NULL == FM) { printf("ERROR: Cannot create FontManager"); return false; }
	if(NULL == SI) { printf("ERROR: Cannot create SerialInterface"); return false; }
	
	RC->initialize(argc, argv);
	TM->initialize();
	VM->initialize();
	
	//FM->initialize();
	BFM->initialize();
	SI->initialize();
	
	RC->setup();
	RC->begin();
	
	VM->shutdown();
	RC->shutdown();
	//FM->shutdown();
	SI->shutdown();
	
	return 0;
};
