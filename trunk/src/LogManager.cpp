#include "afx.h"
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

void LogManager::initialize(){
	
};
void LogManager::shutdown(){
	
};

LogManager* LogManager::m_pInstance = NULL;
