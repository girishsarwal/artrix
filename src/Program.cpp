#include "afx.h"

Program::Program(std::string&){
};
Program::Program(AttributeSet& as){
	m_sName = as.get("name").getValue().c_str();
	m_iProgramHandle = glCreateProgram();
};
Program::~Program(){
	
};

GLuint Program::attachShader(Shader* shader){
	glAttachShader(m_iProgramHandle, shader->getHandle());
	m_Shaders.push_back(shader);
	return shader->incRefCount();
};
GLuint Program::detachShader(Shader* shader){
	glDetachShader(m_iProgramHandle, shader->getHandle());
	//m_Shaders.remove(shader);
	return shader->decRefCount();
};
bool Program::link(){
	printf("linking program '%s' ...", m_sName.c_str());
    glLinkProgram(m_iProgramHandle);
    
    GLint status;
    glGetShaderiv(m_iProgramHandle, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(m_iProgramHandle, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        m_pInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(m_iProgramHandle, infoLogLength, NULL, m_pInfoLog);
		printf("Link failure in program '%s'... \n\t %s\n",m_sName.c_str(), m_pInfoLog);
        delete[] m_pInfoLog;
        return false;
    }
    /** setup the other parameters **/
    m_bIsLinked = true;
     
	printf("Successfully linked program '%s'\n", m_sName.c_str());
	return true;
};

bool Program::bindAttribute(std::string& name, GLuint index){
	glBindAttribLocation(m_iProgramHandle, index, (const GLchar*)name.c_str());
	printf("\t\tAttribute %s bound to location %d\n", name.c_str(), index);
	return true;
};

bool Program::setAttribute(const char* name, float v) const{
	return true;
};
GLuint Program::getAttributeLocation(const char* name) const{
	return true;
};

bool Program::getAttribute(){
	return false;
};

GLuint Program::getUniformLocation(const char* name) const{
	return glGetUniformLocation(m_iProgramHandle, name);
};
bool Program::getUniform(){
	return true;
};
bool Program::setUniform(const char* name, float v) const{
	return true;
};

void Program::setActive(){
	glUseProgram(m_iProgramHandle);
	printf("'%s(%d)' is in use\n", m_sName.c_str(), m_iProgramHandle);
};

GLuint Program::getHandle(){
	return m_iProgramHandle;
};
std::string& Program::getName(){
	return m_sName;
};
bool Program::getIsLinked(){
	return m_bIsLinked;
};




