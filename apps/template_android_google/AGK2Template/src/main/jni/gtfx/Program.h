#ifndef PROGRAM_H
#define PROGRAM_H
#include "afx.h"
#include "KeyManageable.h"
namespace gtfx {
class Shader;
class Program
	: public KeyManageable {
private:

	std::vector<Shader*> mShaders;
	std::map<std::string, GLint> mAttributes;
	std::map<std::string, GLint> mUniforms;

	GLuint mProgramHandle;
	GLchar*	mInfoLog;

	void enumerateUniforms();
	void enumerateAttributes();

	bool mIsLinked;
	bool mIsInitialized;

protected:
public:
	Program();
	Program(tinyxml2::XMLNode*);
	~Program();
	void AttachAllShaders();
	void DetachAllShaders();
	GLuint AttachShader(Shader*);
	GLuint DetachShader(Shader*);
	bool Link();

	bool bindAttribute(std::string&, GLuint);

	GLuint getAttributeLocation(const char* name) const;
	bool getAttribute();
	bool setAttribute(const char* name, float v) const;

	bool registerUniform(const std::string& name);
	GLuint getUniformLocation(const std::string& name);

	void SetUniform1f(const std::string& name, float v1);
	void SetUniform2f(const std::string& name, float v1, float v2);
	void SetUniform3f(const std::string& name, float v1, float v2, float v3) ;
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) ;
	void SetUniform1i(const std::string& name, uint v1);

	void SetUniformMatrix4fv(const std::string& name, glm::mat4);

	void Use();
	void Initialize();
	GLuint getHandle();
	std::string& getName();
	bool getIsLinked();
	bool getIsInitialized();



	string dump() const;
	void Print();
	friend ostream& operator<<(ostream&, const Program&);

	void DetermineSuitableVertexFormat();

};
}
#endif
