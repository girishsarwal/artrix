#include "afx.h"

Shader::Shader(){
	m_iRefCount = 0;
};
Shader::~Shader(){
};

GLuint Shader::compile(GLuint type, std::string& source){
	
	printf("compiling %d shader from code...", type);
	printf("done.\n");
	return false;
};
int Shader::incRefCount(){
	return ++m_iRefCount;
};
int Shader::decRefCount(){
	return --m_iRefCount;
};
