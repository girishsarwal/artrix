#include "LogManager.h"
namespace gtfx {
LogManager::LogManager(){
};

LogManager::~LogManager(){
};

LogManager* LogManager::getInstance(){
	if(NULL == m_pInstance){
		m_pInstance = new LogManager();
	};
	return m_pInstance;
};

void LogManager::Initialize(std::string& logFileName){
	
};
void LogManager::Shutdown(){
	
};

void LogInformation(std::string& message, ...) {
	
}
void LogDebug(std::string& message, ...) {
	
}
void LogWarning(std::string& message, ...) {
	
}
void LogError(std::string& message, ...) {
	
}
void LogVerbose(std::string& message, ...) {
	
}
LogManager* LogManager::m_pInstance = NULL;
}