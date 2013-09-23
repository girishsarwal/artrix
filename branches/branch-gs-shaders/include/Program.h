#include "afx.h"
class Program{
	private:
		std::string 			m_sName;
		std::vector<Shader*>	m_Shaders; 
		std::map<std::string, GLuint> m_Attributes;
		bool					m_bIsLinked;
		GLuint					m_iProgramHandle;
		bool					m_bIsDebug;
		GLchar*					m_pInfoLog;
	public:
		Program(std::string&);
		~Program();
		bool link();
		bool attachShader();
		bool detachShader();
		bool setAttribute(const char* name, float v) const;
		bool setUniform(const char* name, float v) const;
		bool getAttributeLocation(const char* name) const;
		bool getAttribute();
		bool getUniformLocation(const char* name) const;
		bool getUniform();
};
