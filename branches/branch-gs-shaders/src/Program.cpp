#include "afx.h"

Program::Program(std::string&){
};
Program::~Program(){
	
};
bool Program::link(){
	return false;
};
bool Program::attachShader(){
	return false;
};
bool Program::detachShader(){
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

