#include "afx.h"

int main(int argc, char* argv[]){
	if(!RC) { printf("ERROR: Cannot create RenderContext\n"); return false; }
	if(!VM) { printf("ERROR: Cannot create ViewManager\n"); return false; }
	if(!FM) { printf("ERROR: Cannot create FontManager"); return false; }
	if(!SI) { printf("ERROR: Cannot create SerialInterface"); return false; }
	if(!SPM) { printf("ERROR: Cannot create ShaderProgramManager"); return false; }
	
	if(!RC->initialize(argc, argv)){
		throw std::exception();
	}
	TM->initialize();
	SPM->initialize();
		
	VM->initialize();

	BFM->initialize();
	SI->initialize();
	SPI->initialize();
	
	RC->setup();
	RC->begin();
	
	printf("Shutting down subsystems...");
	VM->shutdown();
	RC->shutdown();
	SPI->shutdown();
	SHM->shutdown();
	SI->shutdown();
	printf("Ready to exit");
	
	return 0;
};
