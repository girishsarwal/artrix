#pragma once
#include "afx.h"
#define SHADER_ROOT "/usr/share/artrix/shaders"
struct ProgramShader{
	/*std::string programName;
	GLuint program;*/
	GLuint vs;
	GLuint fs;
	ProgramShader(){
		//program = 0;
		vs=0;
		fs=0;
	}
};
class ShaderManager{
	private:
		std::map<std::string, GLuint> m_pPrograms;
		static ShaderManager* m_pInstance;
		ShaderManager();
		GLuint createVertexShader(const std::string&);
		GLuint createFragmentShader(const std::string&);
		GLuint createShader(GLenum eShaderType, const std::string&);
	public:
		~ShaderManager();
		static ShaderManager* getInstance();
		void useProgram(const std::string&);
		void initialize();
		void shutdown();
};
