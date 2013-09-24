#include "afx.h"

Program::Program(std::string&){
};
Program::Program(AttributeSet& as){
	
};
Program::~Program(){
	
};
bool Program::link(){
	return false;
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
	return false;
};
bool Program::setAttribute(const char* name, float v) const{
	return false;
};
bool Program::setUniform(const char* name, float v) const{
	return false;
};
bool Program::getAttributeLocation(const char* name) const{
	return false;
};
bool Program::getAttribute(){
	return false;
};
bool Program::getUniformLocation(const char* name) const{
	return false;
};
bool Program::getUniform(){
	return false;
};

