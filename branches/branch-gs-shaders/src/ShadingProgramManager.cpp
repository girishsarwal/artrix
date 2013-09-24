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
	createStockShadingPrograms();
	printf("Initialization Complete \n");
	
}
	
void ShadingProgramManager::createStockShadingPrograms(){
	/** read up the shader definition Xml **/
	#ifdef LIBXML_TREE_ENABLED
	xmlDoc* doc = NULL;
	doc = xmlReadFile("/usr/share/artrix/shaders/shaderprograms.xml", NULL, 0);
	for(xmlNode* nodeShadingProgram = xmlDocGetRootElement(doc)->children; nodeShadingProgram; nodeShadingProgram = nodeShadingProgram->next){
		if(strcmp((char*)nodeShadingProgram->name, "text") == 0) continue;
		if(strcmp((char*)nodeShadingProgram->name, "program") == 0){
			printf("Found Shading Program Definition (");
			Program *program = NULL;
			if(NULL != nodeShadingProgram->properties){
				xmlAttr* attrShadingProgram = NULL;
				AttributeSet asProgram;
				for(attrShadingProgram = nodeShadingProgram->properties; attrShadingProgram; attrShadingProgram = attrShadingProgram->next){
					Attribute aShadingProgram;
					aShadingProgram.set((const char*)attrShadingProgram->name, (const char*)xmlGetProp(nodeShadingProgram, attrShadingProgram->name));
					aShadingProgram.display();
					asProgram.add(aShadingProgram);
				}
				/** attributes for shader program created
				 * create a program object now*/
				program = new Program(asProgram);
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
						Attribute aShader;
						aShader.set((const char*)attrShader->name, (const char*)xmlGetProp(nodeShadingProgramSubNode, attrShader->name));
						aShader.display();
						asShader.add(aShader);
					}
					printf(")\n");
					/**attributes have been created
					 * check to see if a shader already exists**/
					std::string source = asShader.get("source").getValue();
					printf("\t\t");
					printf("Looking for shader %s...", source.c_str());
					Shader* shader = NULL;
					std::map <std::string, Shader* >::const_iterator itShader =m_ShaderCache.find(source);
					if(itShader == m_ShaderCache.end()){
						/** read the shader from the source and compile **/
						shader = new Shader(asShader);
						if(shader->compile() > 0){
							m_ShaderCache[source] = shader;
							printf("\tShader is in cache now. Will not be recompiled");
						}
					}
					program->attachShader(shader);
					printf("\n");
				};
				if(strcmp((char*)nodeShadingProgramSubNode->name, "attrib") == 0){ /** shader program attribute **/
					/** set the attributes now**/
					printf("\tFound Attribute (");
					xmlAttr* attrProgramAttribute = NULL;
					AttributeSet asProgramAttribute;
					for(attrProgramAttribute = nodeShadingProgramSubNode->properties; attrProgramAttribute; attrProgramAttribute = attrProgramAttribute->next){
						Attribute aProgramAttribute;
						aProgramAttribute.set((const char*)attrProgramAttribute->name, (const char*)xmlGetProp(nodeShadingProgramSubNode, attrProgramAttribute->name));
						aProgramAttribute.display();
						asProgramAttribute.add(aProgramAttribute);
					}
					printf(")\n");
					std::string name = asProgramAttribute.get("name").getValue();
					int location =  atoi(asProgramAttribute.get("location").getValue().c_str());
					
					program->bindAttribute(name , (GLuint)location);
				};
				if(strcmp((char*)nodeShadingProgramSubNode->name, "uniform") == 0){ /** shader program uniform **/
				}
			}
		}
	}
	#endif
}
void ShadingProgramManager::shutdown(){
};
	
	
	
ShadingProgramManager* ShadingProgramManager::m_pInstance = NULL;
