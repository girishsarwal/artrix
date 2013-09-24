#pragma once
#include "afx.h"
#define SHADER_ROOT "/usr/share/artrix/shaders"
class ShadingProgramManager{
	private:
		std::map<std::string, Program*> m_pPrograms;
		std::map<std::string, Shader*> m_ShaderCache;
		static ShadingProgramManager* m_pInstance;
		ShadingProgramManager();
	public:
		~ShadingProgramManager();
		static ShadingProgramManager* getInstance();
		GLuint getProgramId(const std::string&);
		void createStockShadingPrograms();
		void initialize();
		void shutdown();
};
