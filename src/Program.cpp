#include "afx.h"

Program::Program(std::string&){
};
Program::Program(AttributeSet& as){
	m_sName = as.get("name").getValue().c_str();
	m_iProgramHandle = glCreateProgram();
};
Program::~Program(){
	
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
bool Program::attachShader(Shader* shader){
	shader->incRefCount();
	m_Shaders.push_back(shader);
	return true;
};
bool Program::detachShader(Shader* shader){
	shader->decRefCount();
	//m_Shaders.remove(shader);
	return false;
};
bool Program::bindAttribute(std::string& name, GLuint index){
	glBindAttribLocation(m_iProgramHandle, index, (const GLchar*)name.c_str());
	printf("\t\tAttribute %s bound to location %d\n", name.c_str(), index);
	return true;
};
bool Program::setAttribute(const char* name, float v) const{
	return true;
};
bool Program::setUniform(const char* name, float v) const{
	return true;
};
bool Program::getAttributeLocation(const char* name) const{
	return true;
};
bool Program::getAttribute(){
	return false;
};
bool Program::getUniformLocation(const char* name) const{
	return false;
};
bool Program::getUniform(){
	return true;
};

std::string& Program::getName(){
	return m_sName;
};
bool Program::getIsLinked(){
	return m_bIsLinked;
};
GLuint Program::getHandle(){
	return m_iProgramHandle;
};

