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

void useVertexShader(std::string& shader){
};

void useFragmentShader(std::string& shader){
};

void ShaderManager::initialize(){	
	/** read up all fonts in the font directory **/
	std::string shaderRoot(SHADER_ROOT);
	printf("\nInitializing Shader Manager\n");
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

void ShaderManager::createVertexShader(std::string& shaderFile){
	printf("Creating Vertex Shader\n");
};

void ShaderManager::createFragmentShader(std::string& shaderFile){
	printf("Creating Fragment Shader\n");
};

void ShaderManager::createShader(std::string& shaderFile){
	/** generate display lists **/
#ifdef LIBXML_TREE_ENABLE
#else
	printf("Tree support not compiled");
#endif
	
};

void ShaderManager::shutdown(){
	printf("Shutting Down ShaderManager\n");
};

ShaderManager* ShaderManager::m_pInstance = NULL;
