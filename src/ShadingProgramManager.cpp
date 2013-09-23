#include "afx.h"
ShadingProgramManager::ShadingProgramManager(){
};

ShadingProgramManager::~ShadingProgramManager(){
};

ShadingProgramManager* ShadingProgramManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new ShadingProgramManager();
	};
	return m_pInstance;
};

GLuint ShadingProgramManager::getProgramId(const std::string& program){
	/*GLuint programId = m_pPrograms[program];
	if(programId == 0){
		printf("No shader found for %s\n", program.c_str());
		return 0;
	}
	return programId;*/
	return 0;
};


void ShadingProgramManager::initialize(){	
	printf("+--------------------SHADER MANAGER----------------------+\n");
	printf("Initializing...\n");
	
	/** read up the shader definition Xml **/
	#ifdef LIBXML_TREE_ENABLED
	xmlDoc* doc = NULL;
	doc = xmlReadFile("/usr/share/artrix/shaders/shaderprograms.xml", NULL, 0);
	for(xmlNode* nodeShadingProgram = xmlDocGetRootElement(doc)->children; nodeShadingProgram; nodeShadingProgram = nodeShadingProgram->next){
		if(strcmp((char*)nodeShadingProgram->name, "text") == 0) continue;
		if(strcmp((char*)nodeShadingProgram->name, "program") == 0){
			printf("Found Shading Program Definition (");
			if(NULL != nodeShadingProgram->properties){
				xmlAttr* attrShadingProgram = NULL;
				for(attrShadingProgram = nodeShadingProgram->properties; attrShadingProgram; attrShadingProgram = attrShadingProgram->next){
					const xmlChar* attrShadingProgramName = attrShadingProgram->name;
					const xmlChar* attrShadingProgramValue = xmlGetProp(nodeShadingProgram, attrShadingProgramName);
					printf("%s = %s,", (const char*)attrShadingProgramName, (const char*)attrShadingProgramValue);
				}
			}
			printf(")\n");
			/** read up the shader program's sub children
			 * to idenitfy the shaders involved and the attributes, uniforms etc **/
			for(xmlNode* nodeShadingProgramSubNode = nodeShadingProgram->children; nodeShadingProgramSubNode; nodeShadingProgramSubNode = nodeShadingProgramSubNode->next){
				if(strcmp((char*)nodeShadingProgramSubNode->name, "shader") == 0){	/** shader program **/
					printf("\tFound Shader (");
					xmlAttr* attrShader = NULL;
					AttributeSet asShader;
					for(attrShader = nodeShadingProgramSubNode->properties; attrShader; attrShader = attrShader->next){
						const xmlChar* attrShaderName = attrShader->name;
						const xmlChar* attrShaderValue = xmlGetProp(nodeShadingProgramSubNode, attrShaderName);
						Attribute aShader;
						aShader.set((const char*)attrShaderName, (const char*)attrShaderValue);
						printf("%s = %s,", (const char*)attrShaderName, (const char*)attrShaderValue);
						asShader.add(aShader);
					}
					printf(")\n");
					/**attributes have been created
					 * check to see if a shader already exists**/
					std::string name = asShader.get(std::string("name")).getValue();
					printf("\t\t");
					printf("Looking for shader %s...", name.c_str());
					Shader* shader = NULL;
					std::map <std::string, Shader* >::const_iterator itShader =m_ShaderCache.find(name);
					if(itShader == m_ShaderCache.end()){
						/** read the shader from the source and compile **/
						shader = new Shader();
						if(asShader.get("type").getValue() == "vertex"){ /** shader program attribute **/
							shader->compile(VERTEX, name);
						} else if(asShader.get("type").getValue() == "fragment"){ /** shader program attribute **/
							shader->compile(FRAGMENT, name);
						}
						m_ShaderCache[name] = shader;
						printf("\tShader is in cache now. Will not be recompiled");
					}
					printf("\n");
				};
				if(strcmp((char*)nodeShadingProgramSubNode->name, "attrib") == 0){ /** shader program attribute **/
				};
				if(strcmp((char*)nodeShadingProgramSubNode->name, "uniform") == 0){ /** shader program uniform **/
				}
			}
		};
	}
	#endif
}

void ShadingProgramManager::shutdown(){
};
	
	
	
ShadingProgramManager* ShadingProgramManager::m_pInstance = NULL;
