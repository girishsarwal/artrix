#include "Shader.h"

Shader::Shader(tinyxml2::XMLNode* node){
	
//	m_sShaderType = as.get("type").getValue();
//
//	if(m_sShaderType == "vertex") m_iShaderType = GL_VERTEX_SHADER;
//	else if (m_sShaderType == "geometry") m_iShaderType = GL_GEOMETRY_SHADER;
//	else if (m_sShaderType == "fragment") m_iShaderType = GL_FRAGMENT_SHADER;
//
//	m_sSource = as.get("source").getValue();
};
Shader::Shader(){
	m_iRefCount = 0;
};
Shader::~Shader(){
};

bool Shader::compile(){
	
	printf("compiling %s shader from %s...\n", m_sShaderType.c_str(), m_sSource.c_str());
	chdir("/usr/share/artrix/shaders/");
	/** read up the file **/
    FILE* fp = fopen(m_sSource.c_str(), "r");
    if(NULL == fp){
		printf("Cannot read file %s\n", m_sSource.c_str());
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
    GLuint shader = glCreateShader(m_iShaderType);
    glShaderSource(shader, 1, (const GLchar**) &fileContents, NULL);
    glCompileShader(shader);
    
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        m_pInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, m_pInfoLog);
        printf("%d bytes read\n", length);
		printf("%s", fileContents);
        printf("WARNING: Compile failure in %s shader:\n%s\n",m_sShaderType.c_str(), m_pInfoLog);
        delete[] m_pInfoLog;
        return false;
    }
    /** setup the other parameters **/
    m_bIsCompiled = true;
	m_iShaderHandle = shader;
     
	printf("\t\tSuccessfully compiled program '%s' to handle %d\n", m_sSource.c_str(), m_iShaderHandle);
	return true;
};
int Shader::incRefCount(){
	return ++m_iRefCount;
};
int Shader::decRefCount(){
	return --m_iRefCount;
};
std::string& Shader::getName(){
	return m_sSource;
};
GLuint Shader::getType(){
	return m_iShaderType;
};
bool Shader::getIsCompiled(){
	return m_bIsCompiled;
};
GLuint Shader::getHandle(){
	return m_iShaderHandle;
};
GLint Shader::getReferenceCount(){
	return m_iRefCount;
};
