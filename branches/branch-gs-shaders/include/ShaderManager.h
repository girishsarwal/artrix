#pragma once
#include "afx.h"
#define SHADER_ROOT "/usr/share/artrix/shaders"
class ShaderManager{
	private:
		
		static ShaderManager* m_pInstance;
		ShaderManager();
		void createShader(std::string&);
		void createVertexShader(std::string&);
		void createFragmentShader(std::string&);
	public:
		~ShaderManager();
		static ShaderManager* getInstance();
		void useVertexShader(std::string& shader);
		void useFragmentShader(std::string& shader);
		void initialize();
		void shutdown();
};
