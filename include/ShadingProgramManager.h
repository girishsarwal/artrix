#pragma once
#include "afx.h"
#define SHADER_ROOT "/usr/share/artrix/shaders"
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
		void initialize(const std::string&);
		void shutdown();
};
