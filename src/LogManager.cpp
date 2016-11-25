#include "LogManager.h"
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

void LogManager::initialize(std::string& logFileName){
	
};
void LogManager::shutdown(){
	
};

void logInformation(std::string& message, ...) {

}
void logDebug(std::string& message, ...) {

}
void logWarning(std::string& message, ...) {

}
void logError(std::string& message, ...) {

}
void logVerbose(std::string& message, ...) {

}
LogManager* LogManager::m_pInstance = NULL;
