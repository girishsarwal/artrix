#include "afx.h"

int main(int argc, char* argv[]){
	if(NULL == RC) { printf("ERROR: Cannot create RenderContext\n"); return false; }
	if(NULL == VM) { printf("ERROR: Cannot create ViewManager\n"); return false; }
	if(NULL == FM) { printf("ERROR: Cannot create FontManager"); return false; }
	if(NULL == SI) { printf("ERROR: Cannot create SerialInterface"); return false; }
	if(NULL == SHM) { printf("ERROR: Cannot create ShaderManager"); return false; }
	
	if(!RC->initialize(argc, argv)){
		throw std::exception();
	}
	TM->initialize();
	VM->initialize();
	SHM->initialize();
	SHM->useProgram(std::string("tvc"));
	BFM->initialize();
	SI->initialize();
	SPI->initialize();
	
	RC->setup();
	RC->begin();
	
	VM->shutdown();
	RC->shutdown();
	SPI->shutdown();
	SHM->shutdown();
	SI->shutdown();
	
	return 0;
};
