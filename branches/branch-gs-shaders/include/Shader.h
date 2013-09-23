#include "afx.h"
#define VERTEX 1
#define FRAGMENT 2

class Shader{
		std::string		m_sSource;
		GLuint			m_iShaderType;
			
		bool			m_bIsCompiled;
		GLuint			m_iShaderHandle;
		bool			m_bIsDebug;
		GLint			m_iRefCount;
		GLchar*			m_pInfoLog;
		
	public:
		Shader();
		~Shader();
		GLuint compile(GLuint type, std::string& source);
		int incRefCount();
		int decRefCount();
};
