#include "Program.h"
#include <GL/glew.h>
#include <GL/glut.h>
Program::Program(){
	mProgramHandle = 0;
	mInfoLog= NULL;
	mIsLinked = false;
	mIsInitialized = false;

	SetDefaultName("GPU Program");
};

Program::Program(tinyxml2::XMLNode* node){
	mProgramHandle = 0;
	mInfoLog= NULL;
	mIsLinked = false;
	mIsInitialized = false;

	tinyxml2::XMLElement* elem = node->ToElement();
	if(elem == NULL) {
		printf("\nWARNING: cannot create program");
		return;
	}

	mName = elem->Attribute("name");

	tinyxml2::XMLElement* shaders = elem->FirstChildElement("shaders");
	if(NULL == shaders) {
		printf("\nWARNING: there are no shaders defined. Program may be unuseable");
		return;
	}
	for(tinyxml2::XMLNode* shaderNode = shaders->FirstChild(); shaderNode; shaderNode = shaderNode->NextSibling()) {
		std::string shaderName = shaderNode->FirstChild()->Value();
		Shader* shader = SPM->GetFromShaderCache(shaderName);
		if(NULL == shader){
			printf("\nWARNING: specified shader %s not found in cache. Program may be unuseable", shaderName.c_str());
			continue;
		}
		mShaders.push_back(shader);
	}

//	tinyxml2::XMLElement* attributes = elem->FirstChildElement("attributes");
//	if(NULL == attributes) {
//		printf("\nWARNING: there are no attributes defined. Program may be unusable");
//		return;
//	}
//	for(tinyxml2::XMLNode* attributeNode = attributes->FirstChild(); attributeNode; attributeNode = attributeNode->NextSibling()) {
//		std::string attributeName = attributeNode->ToElement()->Attribute("name");
//		GLuint attributeLocation = atoi(attributeNode->ToElement()->Attribute("location"));
//		mAttributes[attributeName] = attributeLocation;
//	}
//
//	tinyxml2::XMLElement* uniforms = elem->FirstChildElement("uniforms");
//	if(NULL == uniforms) {
//		printf("\nWARNING: there are no uniforms defined. Program may be unusable");
//		return;
//	}
//	for(tinyxml2::XMLNode* uniformNode = uniforms->FirstChild(); uniformNode; uniformNode = uniformNode->NextSibling()) {
//		std::string uniformName = uniformNode->ToElement()->Attribute("name");
//		GLuint uniformLocation = atoi(uniformNode->ToElement()->Attribute("location"));
//		mUniforms[uniformName] = uniformLocation;
//	}
};
Program::~Program(){
	
};
void Program::AttachAllShaders() {
	std::vector<Shader*>::const_iterator it = mShaders.begin();
	while(it != mShaders.end()){
		AttachShader(*it);
		it++;
	}
};

GLuint Program::AttachShader(Shader* shader){
	glAttachShader(mProgramHandle, shader->GetHandle());
	return shader->IncrementRefCount();
};

void Program::DetachAllShaders() {
	std::vector<Shader*>::const_iterator it = mShaders.begin();
	while(it != mShaders.end()){
		DetachShader(*it);
		it++;
	}
};

GLuint Program::DetachShader(Shader* shader){
	glDetachShader(mProgramHandle, shader->GetHandle());
	return shader->DecrementRefCount();
};
bool Program::Link(){
	mIsLinked = false;
	mProgramHandle = glCreateProgram();
	printf("\nLinking program '%s' ...\n", mName.c_str());
	AttachAllShaders();
    glLinkProgram(mProgramHandle);

    GLint status;
    glGetShaderiv(mProgramHandle, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(mProgramHandle, GL_INFO_LOG_LENGTH, &infoLogLength);
        mInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(mProgramHandle, infoLogLength, NULL, mInfoLog);
		printf("\nWARNING: Link failure in program '%s'...\n\t %s",mName.c_str(), mInfoLog);
        delete[] mInfoLog;
        DetachAllShaders();
        return mIsLinked;
    }
    enumerateAttributes();
	enumerateUniforms();
	DetachAllShaders();
	mIsLinked = true;
	printf("\nSuccessfully linked program '%s' to handle %d", mName.c_str(), mProgramHandle);
	return mIsLinked;
};

void Program::enumerateUniforms(){
	GLint numUniforms = 0;
	GLint uniformNameMaxLength = 0;

	glGetProgramiv(mProgramHandle, GL_ACTIVE_UNIFORMS, &numUniforms);
	glGetProgramiv(mProgramHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformNameMaxLength);
	printf("\n\tNo. Of Active Uniforms %d", numUniforms);

	GLint size;
	GLenum type;

	mUniforms.empty();

	while(numUniforms-- > 0){
		GLint location = -1;
		char* _name = (char*)malloc(uniformNameMaxLength);
		glGetActiveUniform(mProgramHandle, numUniforms, uniformNameMaxLength, NULL, &size, &type, _name);
		location = glGetUniformLocation(mProgramHandle, _name);
		std::string name(_name);
		mUniforms[_name] = numUniforms;
		printf("\n\t\tUniform %s coerced to %d", name.c_str(), mUniforms[name]);
	}
}
void Program::enumerateAttributes(){
	GLint numAttributes = 0;
	GLint attributeNameMaxLength = 0;

	glGetProgramiv(mProgramHandle, GL_ACTIVE_ATTRIBUTES, &numAttributes);
	glGetProgramiv(mProgramHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attributeNameMaxLength);

	printf("\n\tNumber of Active Attributes %d", numAttributes);

		GLint size;
		GLenum type;

	mAttributes.empty();

	while(numAttributes-- > 0){
		GLint location = -1;
		char* _name = (char*)malloc(attributeNameMaxLength);
		glGetActiveAttrib(mProgramHandle, numAttributes, attributeNameMaxLength, NULL, &size, &type, _name);
		location = glGetAttribLocation(mProgramHandle, _name);
		std::string name(_name);
		mAttributes[name] = location;
		printf("\n\t\tAttribute %s coerced to %d", name.c_str(), mAttributes[name]);
	}
}

bool Program::bindAttribute(std::string& name, GLuint index){
//	glBindAttribLocation(m_iProgramHandle, index, (const GLchar*)name.c_str());
//	m_AttributeLocations[name] = index;	/** add to map for future **
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

bool Program::registerUniform(const std::string& name){
	//m_UniformLocations[name] = -1;/**just set to -1, will be updated after shader linkage**/
	//printf("\t\tUniform %s registered. Location will be retrieved after linkage\n", name.c_str());
	return true;
};
GLuint Program::getUniformLocation(const std::string& name){
	return glGetUniformLocation(mProgramHandle, name.c_str());
};
bool Program::getUniform(){
	return true;
};
bool Program::setUniform(const std::string& name, float v1) {
	glUniform1f(getUniformLocation(name), v1);
	return true;
};
bool Program::setUniform(const std::string&  name, float v1, float v2) {
	glUniform2f(getUniformLocation(name), v1, v2);
	return true;
};
bool Program::setUniform(const std::string&  name, float v1, float v2, float v3) {
	glUniform3f(getUniformLocation(name), v1, v2, v3);
	return true;
};
bool Program::setUniform(const std::string&  name, float v1, float v2, float v3, float v4) {
	glUniform4f(getUniformLocation(name), v1, v2, v3, v4);
	return true;
};


void Program::Use() {
	if(!mIsInitialized){
		Initialize();
	}
	glUseProgram(mProgramHandle);
};

GLuint Program::getHandle() {
	return mProgramHandle;
};

bool Program::getIsLinked() {
	return mIsLinked;
};

bool Program::getIsInitialized() {
	return mIsLinked;
};

void Program::Initialize(){
	/** compile all shaders **/
	std::vector<Shader*>::const_iterator iter = mShaders.begin();
	while(iter != mShaders.end()){
		(*iter)->Initialize();
		iter++;
	}
	/** link the program **/
	Link();
	mIsInitialized = true;
}


string Program::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Program::Print() {
    printf("Program - %s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Program& program) {
    stream << "<program name=\"" << program.mName << "\">\n";
    std::vector<Shader*>::const_iterator it = program.mShaders.begin();
    while(it != program.mShaders.end()){
    	stream << "<shader>" << (*it)->GetSource() << "</shader>\n";
    	it++;
    }
	//<< "<!-- attributes here-->\n"
	//<< "<!-- uniforms here -->\n"

    stream << "</program>";
    return stream;
}

