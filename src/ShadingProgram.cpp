#include "ShadingProgram.h"
ShadingProgram::ShadingProgram() {
}
;

ShadingProgram::~ShadingProgram() {
}
;

ShadingProgram* ShadingProgram::getInstance() {
	if (NULL == m_pInstance) {
		m_pInstance = new ShadingProgram();
	};
	return m_pInstance;
}
;

GLuint ShadingProgram::getProgramId(const std::string& program) {
	GLuint programId = m_pPrograms[program];
	if (programId == 0) {
		printf("No shader found for %s\n", program.c_str());
		return 0;
	}
	return programId;
}
;

bool ShadingProgram::initialize(const std::string& root) {
	printf("\n+--------------------SHADER MANAGER----------------------+\n");
	printf("Initializing...\n");
	mRoot = root;

	std::string shaderRoot(mRoot);

	DIR* dir;
	dirent* entry;
	dir = opendir(shaderRoot.c_str());
	if (NULL == dir) {
		printf("Error opening shader directory '%s'\n", shaderRoot.c_str());
		return false;
	}
	chdir(shaderRoot.c_str());

	/** create a temporary structure **/
	std::map<std::string, ProgramShader*> programShaders;

	while (NULL != (entry = readdir(dir))) {
		if (entry->d_type != DT_DIR) {
			std::string shaderName = std::string(entry->d_name);
			printf("Found shader %s...", shaderName.c_str());
			std::string ext = shaderName.substr(shaderName.length() - 4, 4);
			std::string canonical_name = shaderName.substr(0,
					shaderName.length() - 5); /**including the .*/
			/** strip the file name and check if we need to create a new
			 * program object or attach to an existing one **/
			ProgramShader* ps = NULL;
			if (programShaders.count(canonical_name) == 0) {
				printf("Creating new program structure\n");
				ps = new ProgramShader();
				programShaders[canonical_name] = ps;
			} else {
				printf("Adding to existing program structure\n");
				ps = programShaders[canonical_name];
			}
			if (ext == "vert") {
				ps->vs = createVertexShader(shaderName);
			} else if (ext == "frag") {
				ps->fs = createFragmentShader(shaderName);
			};
		}
	}

	/**Shaders read from file, compile them to program objects **/
	std::map<std::string, ProgramShader*>::iterator it = programShaders.begin();
	while (it != programShaders.end()) {
		ProgramShader* programShader = it->second;
		printf("Compiling program %s...", it->first.c_str());
		GLuint programId = glCreateProgram();
		glAttachShader(programId, programShader->vs);
		glAttachShader(programId, programShader->fs);
		glLinkProgram(programId);
		GLint status = 0;
		glGetProgramiv(programId, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			GLint infoLogLength = 0;
			glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
			GLchar* infoLog = new GLchar[infoLogLength + 1];
			glGetProgramInfoLog(programId, infoLogLength, NULL, infoLog);
			printf("WARNING: Link failure for program %s shader:\n%s\n",
					it->first.c_str(), infoLog);
			delete[] infoLog;
		} else {
			m_pPrograms[it->first] = programId;
			printf("Done...Program id for %s is %d\n", it->first.c_str(),
					m_pPrograms[it->first]);
			it++;
		}
		glDetachShader(programId, programShader->vs);
		glDetachShader(programId, programShader->fs);
		delete programShader;
	}
	return true;
}
;

GLuint ShadingProgram::createVertexShader(const std::string& shaderFile) {
	printf("Creating Vertex Shader from %s \n", shaderFile.c_str());
	GLuint createdShaderId = createShader(GL_VERTEX_SHADER, shaderFile);
	printf("Vertex Shader %s Created with internal id %d\n", shaderFile.c_str(),
			createdShaderId);
	return createdShaderId;

}
;

GLuint ShadingProgram::createFragmentShader(const std::string& shaderFile) {
	printf("Creating Fragment Shader\n");
	GLuint createdShaderId = createShader(GL_FRAGMENT_SHADER, shaderFile);
	printf("Fragment Shader %s Created with internal id %d\n",
			shaderFile.c_str(), createdShaderId);
	return createdShaderId;
}
;

void ShadingProgram::shutdown() {
	printf("Shutting Down ShadingProgram\n");
	delete m_pInstance;
}
;

GLuint ShadingProgram::createShader(GLenum eShaderType,
		const std::string &shaderFile) {
	/** read up the file **/
	FILE* fp = fopen(shaderFile.c_str(), "r");
	if (NULL == fp) {
		printf("Cannot read file %s\n", shaderFile.c_str());
		return 0;
	}
	/** get hold of the file length**/
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);

	rewind(fp);
	char* fileContents = (char*) malloc(sizeof(char) * (length + 1));
	length = fread(fileContents, sizeof(char), length, fp);

	fileContents[length] = '\0';
	fclose(fp);
	GLuint shader = glCreateShader(eShaderType);
	glShaderSource(shader, 1, (const GLchar**) &fileContents, NULL);
	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *infoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);

		const char *shaderType = NULL;
		switch (eShaderType) {
		case GL_VERTEX_SHADER:
			shaderType = "vertex";
			break;
		case GL_GEOMETRY_SHADER:
			shaderType = "geometry";
			break;
		case GL_FRAGMENT_SHADER:
			shaderType = "fragment";
			break;
		}
		printf("%d bytes read\n", length);
		printf("%s", fileContents);
		printf("Compile failure in %s shader:\n%s\n", shaderType, infoLog);

		delete[] infoLog;
		return 0;
	}
	return shader;
}

ShadingProgram* ShadingProgram::m_pInstance = NULL;
