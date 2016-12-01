#include "Shader.h"

Shader::Shader(tinyxml2::XMLNode* node){
	mRefCount = 0;
	mIsCompiled = false;
	mIsInitialized = false;
	mShaderHandle = 0;
	tinyxml2::XMLElement* elem = node->ToElement();
	if(elem == NULL){
		printf("\nWARNING: Cannot create shader");
		return;
	}
	mRoot = SPM->GetRoot();
	mName = elem->Attribute("source");
	mSource = elem->Attribute("source");
	mShaderType = elem->Attribute("type");
};
Shader::Shader(){
	mRefCount = 0;
	mIsCompiled = false;
	mIsInitialized = false;
	mRoot = SPM->GetRoot();
	mShaderHandle = 0;
	SetDefaultName("Shader");
};

Shader::~Shader(){
};



const std::string& Shader::GetRoot() const {
	return mRoot;
};

void Shader::SetRoot(const std::string& root) {
	mRoot = root;
	mFile = mRoot + "/" + mSource;
};

const std::string& Shader::GetSource() const {
	return mSource;
};

void Shader::SetSource(const std::string& source) {
	mSource = source;
	mFile = mRoot + "/" + mSource;
};

const std::string& Shader::GetType() const{
	return mShaderType;
};

void Shader::SetType(const std::string& type) {
	mShaderType = type;
};

bool Shader::GetIsInitialized() {
    return mIsInitialized;
}

int Shader::IncrementRefCount(){
	return ++mRefCount;
};
int Shader::DecrementRefCount(){
	return --mRefCount;
};

bool Shader::GetIsCompiled(){
	return mIsCompiled;
};

GLuint Shader::GetHandle(){
	return mShaderHandle;
};

GLint Shader::GetReferenceCount(){
	return mRefCount;
};


void Shader::Initialize() {
	SetName(mName);
	SetRoot(mRoot);
	SetSource(mSource);
	SetType(mShaderType);
	Compile();
    mIsInitialized = true;
}

bool Shader::Compile(){
	printf("\nCompiling %s shader from %s...\n", mShaderType.c_str(), mFile.c_str());
    FILE* fp = fopen(mFile.c_str(), "r");
    if(NULL == fp){
		printf("\nWARNING: Cannot read file %s\n", mFile.c_str());
		return false;
	}
	/** get hold of the file length**/
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);

    rewind(fp);
    char* fileContents = (char*)malloc(sizeof(char) * (length + 1));
    length = fread(fileContents, sizeof(char), length, fp);

    fileContents[length] = '\0';
    fclose(fp);
    mShaderHandle = glCreateShader(GetShaderType(mShaderType));
    glShaderSource(mShaderHandle, 1, (const GLchar**) &fileContents, NULL);
    glCompileShader(mShaderHandle);
    GLint status;
    glGetShaderiv(mShaderHandle, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(mShaderHandle, GL_INFO_LOG_LENGTH, &infoLogLength);

        mInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(mShaderHandle, infoLogLength, NULL, mInfoLog);
        printf("\nWARNING: Compile failure in shader %s (%d bytes)...\n\t %s \n %s",mSource.c_str(), length, fileContents, mInfoLog);
        delete[] mInfoLog;
        return false;
    }
    /** setup the other parameters **/
    mIsCompiled = true;

	printf("\tSuccessfully compiled program '%s' to handle %d", mSource.c_str(), mShaderHandle);
	return mIsCompiled;
};

GLuint	Shader::GetShaderType(const std::string& type) {
	if(type == "vertex"){
		return VERTEX_SHADER;
	} else if (type == "fragment") {
		return FRAG_SHADER;
	} else {
		printf("\nWARNING: cannot determine shader type from '%s'", type.c_str());
		return -1;
	}
}


string Shader::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Shader::Print() {
    printf("Shader - %s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Shader& shader) {
    stream << "<shader source=\"" << shader.mSource << "\" type=\"" << shader.mShaderType << "\">" << "</shader>";
    return stream;
}
