#include "afx.h"
class Program{
	private:
		std::string 			m_sName;
		std::vector<Shader*>	m_Shaders; 
		std::map<std::string, GLuint> m_Attributes;
		std::map<std::string, GLuint> m_Uniforms;
		bool					m_bIsLinked;
		GLuint					m_iProgramHandle;
		GLchar*					m_pInfoLog;
	public:
		Program(std::string&);
		Program(AttributeSet&);
		~Program();
		bool link();
		bool attachShader(Shader*);
		bool detachShader(Shader*);
		bool bindAttribute(std::string&, GLuint);
		bool setAttribute(const char* name, float v) const;
		bool setUniform(const char* name, float v) const;
		bool getAttributeLocation(const char* name) const;
		bool getAttribute();
		bool getUniformLocation(const char* name) const;
		bool getUniform();
		
		std::string& getName();
		bool getIsLinked();
		GLuint getHandle();
};
