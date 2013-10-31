#include "afx.h"

class Shader{
		std::string		m_sSource;
		GLuint			m_iShaderType;
		std::string		m_sShaderType;
		bool			m_bIsCompiled;
		GLuint			m_iShaderHandle;
		GLint			m_iRefCount;
		GLchar*			m_pInfoLog;
		
	public:
		Shader(AttributeSet&);
		Shader();
		~Shader();
		
		GLuint compile();
		
		int incRefCount();
		int decRefCount();
		
		std::string& 	getName();
		GLuint 			getType();
		bool 			getIsCompiled();
		GLuint 			getHandle();
		GLint 			getReferenceCount();
};
