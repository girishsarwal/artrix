#pragma once
#include "afx.h"
class LogManager{
private:
	std::string	m_sLogFile;
	int	m_iLogLevel;
	static LogManager* m_pInstance;
	LogManager();
	void log(std::string& message, ...);
public:
	void initialize(std::string& logFileName);
	void shutdown();
	void logInformation(std::string& message, ...);
	void logDebug(std::string& message, ...);
	void logWarning(std::string& message, ...);
	void logError(std::string& message, ...);
	void logVerbose(std::string& message, ...);
	static LogManager* getInstance();
	~LogManager();
};

