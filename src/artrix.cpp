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
#include "VertexDefinitionManager.h"

gtfx::RenderContext* rc  = NULL;
gtfx::ViewManager* vm = NULL;

#define TESTMODE

int main(int argc, char* argv[]){

	rc = gtfx::RenderContext::GetInstance();
	if(!rc) { printf("ERROR: Cannot create RenderContext\n"); return false; }

	vm = gtfx::ViewManager::GetInstance();
	if(!gtfx::ViewManager::GetInstance()) { printf("ERROR: Cannot create ViewManager\n"); return false; }

	if(!DM) { printf("ERROR: Cannot create DLCManager"); return false; }
	gtfx::VertexDefinitionManager::CreateVertexDefinitions();

	if(!TM) { printf("ERROR: Cannot create TextureManager\n"); return false; }

	if(!FM) { printf("ERROR: Cannot create FontManager"); return false; }
	if(!RS232M) { printf("ERROR: Cannot create SerialManager"); return false; }
	if(!SPI) { printf("ERROR: Cannot create ShaderProgramManager"); return false; }

	if(!DM->initialize("http://availability.localhost.com", "/artrix")) {	/** DLC Manager **/
		throw std::exception();
	}

	DM->FromMediaServer("/pratham.zip", "./.artrix/dlc/", true);
	if(!rc->initialize(argc, argv)){
		throw std::exception();
	}

	if(!TM->initialize("./.artrix/dlc/pratham/textures", "textures.mf")) {	/** Texture Manager **/
		throw std::exception();
	}

	if(!SPM->initialize("./.artrix/dlc/pratham/shaders", "shaderprograms.mf")) { 	/** Shading Program Manager **/
		throw std::exception();
	}

	if(!vm->initialize("./.artrix/dlc/pratham/screens", "screens.mf")) { 	/** View Manager **/
		throw std::exception();
	}


	if(!BFM->initialize("./.artrix/dlc/pratham/fonts", "fonts.mf")) {		/** BM Font Manager **/
		throw std::exception();
	}
	if(!RS232M->initialize("/dev/ttyS0")) { 				/** Serial Interface Manager **/
		throw std::exception();
	}

	if(!SPI->initialize("/dev/spidev")) {				/** SPI Manager **/
		throw std::exception();
	}


	rc->begin();

	printf("Shutting down subsystems...");
	vm->shutdown();
	rc->shutdown();
	SPI->shutdown();
	SPM->shutdown();
	RS232M->shutdown();

	printf("Ready to exit");
	
	return 0;
};


