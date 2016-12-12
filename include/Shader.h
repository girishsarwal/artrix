#ifndef SHADER_H
#define SHADER_H
#define VERTEX_SHADER GL_VERTEX_SHADER
#define FRAG_SHADER	GL_FRAGMENT_SHADER
#include "afx.h"
#include "KeyManageable.h"
namespace gtfx {
class Shader :
	public KeyManageable {

private:
	GLint			mRefCount;
	GLchar*			mInfoLog;
	GLint			mShaderHandle;


protected:
	std::string		mRoot;
	std::string		mSource;
	std::string		mFile;
	std::string		mShaderType;
	bool			mIsCompiled;
	bool			mIsInitialized;

	GLuint	GetShaderType(const std::string&);
public:
	Shader(tinyxml2::XMLNode*);
	Shader();
	~Shader();

	bool Compile();

	int IncrementRefCount();
	int DecrementRefCount();

	const std::string& GetRoot() const;
	void SetRoot(const std::string&);
	const std::string& GetSource() const;
	void SetSource(const std::string&);
	const std::string& GetType() const;
	void SetType(const std::string&);
	bool GetIsCompiled();
	bool GetIsInitialized();
	GLuint GetHandle();
	GLint GetReferenceCount();

	void Initialize();

    /** Debug **/
    string dump() const;
    virtual void Print();
    friend ostream& operator<<(ostream& stream, const Shader& widget);
};
}
#endif
