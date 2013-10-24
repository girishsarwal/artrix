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
	printf("Looking for program %s \n", program.c_str());
	Program *pProgram = m_pProgramCache[program];
	if(NULL == pProgram){ 
		printf("No program found for %s\n", program.c_str());
		return 0;
	}
	GLuint programId = pProgram->getHandle();
	if(0 > programId){
		printf("Hell shader found for %s\n", program.c_str());
		return 0;
	}
	return programId;
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
		if(strcmp((char*)nodeShadingProgram->name, "comment") == 0) continue;
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
							/** add it to the cache **/
							m_ShaderCache[shader->getName()] = shader;
							printf("\tShader is in cache now with id %s and handle %d. Will not be recompiled", shader->getName().c_str(), shader->getHandle());
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
			/** see if program is not in cache then compile and 
			 *  link it now **/
			std::map <std::string, Program* >::const_iterator itProgram = m_pProgramCache.find(program->getName());
			if(itProgram == m_pProgramCache.end()){
				if(program->link() > 0){
					m_pProgramCache[program->getName()] = program;
					printf("\tProgram is in cache now with id %s and handle %d. Will not be re-linked\n", program->getName().c_str(), program->getHandle());
				}
			}
		}
		
				
	}
	#endif
}
void ShadingProgramManager::shutdown(){
};
	
	
	
ShadingProgramManager* ShadingProgramManager::m_pInstance = NULL;
