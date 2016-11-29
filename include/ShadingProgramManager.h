#ifndef SHADINGPROGRAMMANAGER_H
#define SHADINGPROGRAMMANAGER_H
class Program;
class Shader;
#include "afx.h"
#include "Shader.h"
#include "Program.h"
#include "KeyedManager.h"
class ShadingProgramManager
	: public KeyedManager<Program*>{
	private:
		std::string mRoot;
		std::string mManifest;

		KeyedManager<Shader*> mShaderCache;

		static ShadingProgramManager* m_pInstance;
		ShadingProgramManager();
	public:
		~ShadingProgramManager();
		static ShadingProgramManager* getInstance();
		const std::string& GetRoot() const;
		void AddToShaderCache(Shader*);
		Shader* GetFromShaderCache(const std::string&);
		bool CreateStockShadingPrograms();
		void Use(const std::string&);
		bool initialize(const std::string&, const std::string&);
		void shutdown();
};
#define SPM ShadingProgramManager::getInstance()
#endif
