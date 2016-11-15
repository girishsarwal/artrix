#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H
#include "afx.h"
struct ProgramShader{
	GLuint vs;
	GLuint fs;
	
	ProgramShader(){
		vs=0;
		fs=0;
	}
	
};
class ShaderManager{
	private:
		std::map<std::string, GLuint> m_pPrograms;
		static ShaderManager* m_pInstance;
		ShaderManager();
		std::string mRoot;
		GLuint createVertexShader(const std::string&);
		GLuint createFragmentShader(const std::string&);
		GLuint createShader(GLenum eShaderType, const std::string&);
	public:
		~ShaderManager();
		static ShaderManager* getInstance();
		GLuint getProgramId(const std::string&);
		bool initialize(const std::string&);
		void shutdown();
};
#endif
