#ifndef SHADINGPROGRAMMANAGER_H
#define SHADINGPROGRAMMANAGER_H
class Program;
class Shader;
#include "afx.h"
#include "Shader.h"
#include "Program.h"
#include "ShaderProgram.h"
#include "KeyedManager.h"
class ShadingProgramManager
	: public KeyedManager<ShadingProgram*>{
	private:
		std::string mRoot;
		std::string mManifest;

		KeyedManager<Shader*> mShaderCache;

		static ShadingProgramManager* m_pInstance;
		ShadingProgramManager();
	public:
		~ShadingProgramManager();
		static ShadingProgramManager* getInstance();
		Program* getProgram(const std::string&);
		void AddToShaderCache(Shader*);
		Shader* GetFromShaderCache(const std::string&);
		bool CreateStockShadingPrograms();
		bool initialize(const std::string& root, const std::string& manifest);
		void shutdown();
};
#define SPM ShadingProgramManager::getInstance()
#endif
