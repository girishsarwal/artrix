#pragma once
#include "afx.h"
#define SHADER_ROOT "/usr/share/artrix/shaders"
class ShaderManager{
	private:
		std::map<std::string, GLuint> m_pShaders;
		static ShaderManager* m_pInstance;
		ShaderManager();
		void createVertexShader(const std::string&);
		void createFragmentShader(const std::string&);
		void createShader(GLenum eShaderType, const std::string&);
	public:
		~ShaderManager();
		static ShaderManager* getInstance();
		void useVertexShader(const std::string&);
		void useFragmentShader(const std::string&);
		void initialize();
		void shutdown();
};
