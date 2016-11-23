#include "ShadingProgramManager.h"
ShadingProgramManager::ShadingProgramManager(){
};

ShadingProgramManager::~ShadingProgramManager(){
};

ShadingProgramManager* ShadingProgramManager::getInstance(){
	if(!m_pInstance){
		m_pInstance = new ShadingProgramManager();
	};
	return m_pInstance;
};


bool ShadingProgramManager::initialize(const std::string& root, const std::string& manifest){
	mRoot = root;
	mManifest = manifest;

	printf("\n+--------------------SHADING PROGRAM MANAGER----------------------+\n");
	printf("Initializing...\n");
	printf("Looking for shader definitions in %s \n", mRoot.c_str());

	return CreateStockShadingPrograms();
}
void ShadingProgramManager::AddToShaderCache(Shader* shader) {
	mShaderCache.Add(shader);
};

Shader* ShadingProgramManager::GetFromShaderCache(const std::string& name) {
	return mShaderCache.Get(name);
};

bool ShadingProgramManager::CreateStockShadingPrograms(){
	std::string manifest = mRoot+ "/" + mManifest;
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError result = doc.LoadFile(manifest.c_str());

	if(result != tinyxml2::XML_SUCCESS){
		printf("cannot open manifest %s", manifest.c_str());
		return false;
	}


	printf("\n *** Enumerating shaders ***;");
	tinyxml2::XMLElement* shadersNode = doc.RootElement()->FirstChildElement("shaders");
	if(NULL == shadersNode) {
		printf("\nWARNING: No shaders defined");
		return true;
	}
	for (tinyxml2::XMLNode *shaderNode = shadersNode->FirstChild(); shaderNode; shaderNode = shaderNode->NextSibling()) {
		Shader* shader = new Shader(shaderNode);
		mShaderCache.Add(shader);
	}
	printf("\n *** Enumerating gpu programs ***");
	tinyxml2::XMLElement* gpuProgramsNode = doc.RootElement()->FirstChildElement("programs");
	if(NULL == gpuProgramsNode) {
		printf("\nWARNING: No gpu programs defined");
		return true;
	}
	for (tinyxml2::XMLNode *gpuProgramNode = gpuProgramsNode->FirstChild(); gpuProgramNode; gpuProgramNode = gpuProgramNode->NextSibling()) {
		Program* program = new Program(gpuProgramNode);
		SPM->Add(program);
	}

	return true;
}
const std::string& ShadingProgramManager::GetRoot() const{
	return mRoot;
}
void ShadingProgramManager::shutdown(){
};	

void ShadingProgramManager::Use(const std::string& name){
	Program* program = Get(name);
	if(NULL == program) {
		printf("\nWARNING: cannot find program %s", name.c_str());
		return;
	}
	program->Use();
}

ShadingProgramManager* ShadingProgramManager::m_pInstance = NULL;
