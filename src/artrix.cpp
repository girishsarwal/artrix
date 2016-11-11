#include "afx.h"

int main(int argc, char* argv[]){
	if(!DM) { printf("ERROR: Cannot create DLCManager"); return false; }
	if(!RC) { printf("ERROR: Cannot create RenderContext\n"); return false; }
	if(!VM) { printf("ERROR: Cannot create ViewManager\n"); return false; }
	if(!FM) { printf("ERROR: Cannot create FontManager"); return false; }
	if(!SI) { printf("ERROR: Cannot create SerialInterface"); return false; }
	if(!SPM) { printf("ERROR: Cannot create ShaderProgramManager"); return false; }
	
	if(!DM->initialize("http://availability.localhost.com", "/devops/manifests/")) {	/** DLC Manager **/
		throw std::exception();
	}

	if(!RC->initialize(argc, argv)){
		throw std::exception();
	}

	if(!TM->initialize("/usr/share/artrix/images")) {	/** Texture Manager **/
			throw std::exception();
	}

	if(!SPM->initialize("/usr/share/artrix/shaders")) { 	/** Shading Program Manager **/
			throw std::exception();
	}

	if(!VM->initialize("/usr/share/artrix/screens")) { 	/** View Manager **/
		throw std::exception();
	}

	if(!BFM->initialize("/usr/share/artrix/fonts")) {		/** BM Font Manager **/
		throw std::exception();
	}

	if(!SI->initialize("/dev/ttyS0")) { 				/** Serial Interface Manager **/
		throw std::exception();
	}

	if(!SPI->initialize("/dev/spidev")) {				/** SPI Manager **/
		throw std::exception();
	}


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
