#include "afx.h"
#include "ViewManager.h"
#include "RenderContext.h"
#include "DownloadManager.h"
#include "FontManager.h"
#include "BMFontManager.h"
#include "SerialManager.h"
#include "SPIManager.h"
#include "TextureManager.h"
#include "ShadingProgramManager.h"

#define TESTMODE
int main(int argc, char* argv[]){
	if(!DM) { printf("ERROR: Cannot create DLCManager"); return false; }
	if(!RC) { printf("ERROR: Cannot create RenderContext\n"); return false; }
	if(!TM) { printf("ERROR: Cannot create TextureManager\n"); return false; }
	if(!VM) { printf("ERROR: Cannot create ViewManager\n"); return false; }
	if(!FM) { printf("ERROR: Cannot create FontManager"); return false; }
	if(!RS232M) { printf("ERROR: Cannot create Serialmanager"); return false; }
	if(!SPI) { printf("ERROR: Cannot create ShaderProgramManager"); return false; }
	
	if(!DM->initialize("http://availability.localhost.com", "/artrix")) {	/** DLC Manager **/
		throw std::exception();
	}
#ifdef TESTMODE

	DM->FromMediaServer("/pratham.zip", "./.artrix/pratham", true);
	if(!RC->initialize(argc, argv)){
		throw std::exception();
	}

	if(!TM->initialize("./.artrix/pratham/images")) {	/** Texture Manager **/
			throw std::exception();
	}
#else
	if(!SPM->initialize("/dev/share/artrix/shaders")) { 	/** Shading Program Manager **/
			throw std::exception();
	}

	if(!VM->initialize("/usr/share/artrix/screens")) { 	/** View Manager **/
		throw std::exception();
	}

	if(!BFM->initialize("/usr/share/artrix/fonts")) {		/** BM Font Manager **/
		throw std::exception();
	}

	if(!RS232M->initialize("/dev/ttyS0")) { 				/** Serial Interface Manager **/
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
	SPM->shutdown();
	RS232M->shutdown();

	printf("Ready to exit");
#endif
	
	return 0;
};

