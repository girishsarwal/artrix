#include "afx.h"
ShaderManager::ShaderManager(){
};

ShaderManager::~ShaderManager(){
};

ShaderManager* ShaderManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new ShaderManager();
	};
	return m_pInstance;
};

void useVertexShader(const std::string& shader){
};

void useFragmentShader(const std::string& shader){
};

void ShaderManager::initialize(){	
	printf("+--------------------SHADER MANAGER----------------------+\n");
	printf("Initializing...\n");
	/** read up all fonts in the font directory **/
	std::string shaderRoot(SHADER_ROOT);
	DIR* dir;
	dirent* entry;
	dir = opendir(shaderRoot.c_str());
	if(NULL == dir){
		printf("Error opening shader directory '%s'\n", shaderRoot.c_str());
		return;
	}
	chdir(shaderRoot.c_str());
	while(NULL != (entry = readdir(dir))){
		if(entry->d_type != DT_DIR){
			std::string shaderName= std::string(entry->d_name);			
			printf("Found shader %s\n", shaderName.c_str());
			std::string ext = shaderName.substr(shaderName.length() - 4, 4);
			if(ext == "vert"){
				createVertexShader(shaderName);
			} else if(ext == "frag"){
				createFragmentShader(shaderName);
			};
		}
	}
};

void ShaderManager::createVertexShader(const std::string& shaderFile){
	printf("Creating Vertex Shader from %s \n", shaderFile.c_str());
	createShader(GL_VERTEX_SHADER, shaderFile);
	
};

void ShaderManager::createFragmentShader(const std::string& shaderFile){
	printf("Creating Fragment Shader\n");
	createShader(GL_FRAGMENT_SHADER, shaderFile);
};

void ShaderManager::shutdown(){
	printf("Shutting Down ShaderManager\n");
};

void ShaderManager::createShader(GLenum eShaderType, const std::string &shaderFile)
{
    /** read up the file **/
    FILE* fp = fopen(shaderFile.c_str(), "r");
    if(NULL == fp){
		printf("Cannot read file %s\n", shaderFile.c_str());
		return;
	}
	/** get hold of the file length**/
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	
    rewind(fp);
    char* fileContents = (char*)malloc(sizeof(char) * (length + 1));
    length = fread(fileContents, sizeof(char), length, fp);
    printf("%d bytes read\n", length);
    fileContents[length] = '\0';
    fclose(fp);
	printf("%s", fileContents);
    GLuint shader = glCreateShader(eShaderType);
    glShaderSource(shader, 1, (const GLchar**) &fileContents, NULL);
    glCompileShader(shader);
    
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar *infoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
        
        const char *shaderType = NULL;
        switch(eShaderType)
        {
			case GL_VERTEX_SHADER: shaderType = "vertex"; break;
			case GL_GEOMETRY_SHADER: shaderType = "geometry"; break;
			case GL_FRAGMENT_SHADER: shaderType = "fragment"; break;
        }
        
        printf("Compile failure in %s shader:\n%s\n", shaderType, infoLog);
        delete[] infoLog;
        return;
    }
	m_pShaders[shaderFile] == shader;
	printf("Shader %s Created with internal id %d\n", shaderFile.c_str(), m_pShaders[shaderFile]);
}

ShaderManager* ShaderManager::m_pInstance = NULL;
