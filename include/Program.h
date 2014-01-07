#include "afx.h"
class Program{
	private:
		std::string 			m_sName;
		std::vector<Shader*>	m_Shaders; 
		std::map<std::string, GLuint> m_AttributeLocations;
		std::map<std::string, GLuint> m_UniformLocations;
		bool					m_bIsLinked;
		GLuint					m_iProgramHandle;
		GLchar*					m_pInfoLog;
		
		void					enumerateUniforms();
		void					enumerateAttributes();
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

		bool registerUniform(const std::string& name);
		GLuint getUniformLocation(const std::string& name);
		bool getUniform();
		bool setUniform(const std::string&  name, float v1) ;
		bool setUniform(const std::string&  name, float v1, float v2) ;
		bool setUniform(const std::string&  name, float v1, float v2, float v3) ;
		bool setUniform(const std::string&  name, float v1, float v2, float v3, float v4) ;

		void setActive();

		GLuint getHandle();
		std::string& getName();
		bool getIsLinked();
};
