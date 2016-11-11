#ifndef SHADER_H
#define SHADER_H
#include "afx.h"
#include <GL/glut.h>
#include <GL/glew.h>
#include <stdio.h>
class Shader{
		std::string		m_sSource;
		GLuint			m_iShaderType;
		std::string		m_sShaderType;
		bool			m_bIsCompiled;
		GLuint			m_iShaderHandle;
		GLint			m_iRefCount;
		GLchar*			m_pInfoLog;
		
	public:
		Shader(tinyxml2::XMLNode*);
		Shader();
		~Shader();
		
		bool compile();
		
		int incRefCount();
		int decRefCount();
		
		std::string& 	getName();
		GLuint 			getType();
		bool 			getIsCompiled();
		GLuint 			getHandle();
		GLint 			getReferenceCount();
};
#endif
