#ifndef PROGRAM_H
#define PROGRAM_H
#include "afx.h"
#include "Shader.h"
#include "KeyManageable.h"
#include "KeyedManager.h"
#include "ShadingProgramManager.h"
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
	bool getUniform();
	bool setUniform(const std::string&  name, float v1) ;
	bool setUniform(const std::string&  name, float v1, float v2) ;
	bool setUniform(const std::string&  name, float v1, float v2, float v3) ;
	bool setUniform(const std::string&  name, float v1, float v2, float v3, float v4) ;

	void Use();
	void Initialize();
	GLuint getHandle();
	std::string& getName();
	bool getIsLinked();
	bool getIsInitialized();



	string dump() const;
	void Print();
	friend ostream& operator<<(ostream&, const Program&);

};
#endif
