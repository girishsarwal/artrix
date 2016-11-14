#ifndef SHADINGPROGRAMMANAGER_H
#define SHADINGPROGRAMMANAGER_H
class Program;
class Shader;
#include "afx.h"
#include "Shader.h"
#include "Program.h"
class ShadingProgramManager{
	private:
		std::map<std::string, Program*> m_pProgramCache;
		std::map<std::string, Shader*> m_ShaderCache;
		std::string m_root;
		static ShadingProgramManager* m_pInstance;
		ShadingProgramManager();
	public:
		~ShadingProgramManager();
		static ShadingProgramManager* getInstance();
		Program* getProgram(const std::string&);
		void createStockShadingPrograms();
		bool initialize(const std::string&);
		void shutdown();
};
#define SPM ShadingProgramManager::getInstance()
#endif
