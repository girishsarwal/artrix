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
		
		GLuint attachShader(Shader*);
		GLuint detachShader(Shader*);
		bool link();

		bool bindAttribute(std::string&, GLuint);

		GLuint getAttributeLocation(const char* name) const;
		bool getAttribute();
		bool setAttribute(const char* name, float v) const;

		GLuint getUniformLocation(const char* name) const;
		bool getUniform();
		bool setUniform(const char* name, float v) const;

		void setActive();

		GLuint getHandle();
		std::string& getName();
		bool getIsLinked();
};
