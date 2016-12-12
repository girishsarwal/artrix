#include "afx.h"
#include "ViewManager.h"
#include "RenderContext.h"
#include "DownloadManager.h"
#include "BMFontManager.h"
#include "SerialManager.h"
#include "SPIManager.h"
#include "TextureManager.h"
#include "ShadingProgramManager.h"
#include "VertexDefinitionManager.h"

gtfx::RenderContext* rc  = NULL;
gtfx::ViewManager* vm = NULL;
gtfx::DownloadManager* dm = NULL;
gtfx::TextureManager* tm  = NULL;
gtfx::ShadingProgramManager * spm  = NULL;
gtfx::SerialManager* rs232m = NULL;
gtfx::BMFontManager* bfm = NULL;
gtfx::SPIManager* spim = NULL;

#define TESTMODE

int main(int argc, char* argv[]){

	dm = gtfx::DownloadManager::GetInstance();
	if(!dm) { printf("ERROR: Cannot create DLCManager"); return false; }

	rc = gtfx::RenderContext::GetInstance();
	if(!rc) { printf("ERROR: Cannot create RenderContext\n"); return false; }

	gtfx::VertexDefinitionManager::CreateVertexDefinitions();


	tm = gtfx::TextureManager::GetInstance();
	if(!tm) { printf("ERROR: Cannot create TextureManager\n"); return false; }

	bfm = gtfx::BMFontManager::GetInstance();
	if(!bfm) { printf("ERROR: Cannot create BitmapFontManager"); return false; }

	spm = gtfx::ShadingProgramManager::GetInstance();
	if(!spm) { printf("ERROR: Cannot create ShaderProgramManager"); return false; }

	vm = gtfx::ViewManager::GetInstance();
	if(!vm) { printf("ERROR: Cannot create ViewManager\n"); return false; }

	rs232m = gtfx::SerialManager::GetInstance();
	if(!rs232m) { printf("ERROR: Cannot create SerialManager"); return false; }

	spim = gtfx::SPIManager::GetInstance();
	if(!rs232m) { printf("ERROR: Cannot create SPIManager"); return false; }

	if(!dm->initialize("http://availability.localhost.com", "/artrix")) {	/** DLC Manager **/
		throw std::exception();
	}

	dm->FromMediaServer("/pratham.zip", "./.artrix/dlc/", true);

	if(!rc->initialize(argc, argv)){
		throw std::exception();
	}

	if(!tm->initialize("./.artrix/dlc/pratham/textures", "textures.mf")) {	/** Texture Manager **/
		throw std::exception();
	}

	if(!bfm->initialize("./.artrix/dlc/pratham/fonts", "fonts.mf")) {		/** BM Font Manager **/
		throw std::exception();
	}

	if(!spm->initialize("./.artrix/dlc/pratham/shaders", "shaderprograms.mf")) { 	/** Shading Program Manager **/
			throw std::exception();
	}

	if(!vm->initialize("./.artrix/dlc/pratham/screens", "screens.mf")) { 	/** View Manager **/
		throw std::exception();
	}


	if(!rs232m->initialize("/dev/ttyS0")) { 				/** Serial Interface Manager **/
		throw std::exception();
	}

	if(!spim->initialize("/dev/spidev")) {				/** SPI Manager **/
		throw std::exception();
	}


	rc->begin();

	printf("Shutting down subsystems...");
	spim->shutdown();
	rs232m->shutdown();
	vm->shutdown();
	spm->shutdown();
	bfm->shutdown();
	tm->shutdown();
	rc->shutdown();
	dm->shutdown();
	printf("Ready to exit");
	
	return 0;
};


