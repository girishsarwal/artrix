#pragma once
#include "afx.h"
class LogManager{
private:
	std::string	m_sLogFile;
	int	m_iLogLevel;
	static LogManager* m_pInstance;
	LogManager();

public:
	void initialize();
	void shutdown();
	void log(std::string& message);
	static LogManager* getInstance();
	~LogManager();
};

