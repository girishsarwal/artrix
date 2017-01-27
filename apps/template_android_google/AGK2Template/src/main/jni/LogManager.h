#pragma once
#include <android/log.h>
#include <string>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "artrix", __VA_ARGS__))
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, "artrix", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARM, "artrix", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "artix", __VA_ARGS__))
#define LOGV(...) ((void)__android_log_print(ANDROID_LOG_VERBOSE, "artrix", __VA_ARGS__))
namespace gtfx{
class LogManager{
private:
	std::string	m_sLogFile;
	int	m_iLogLevel;
	static LogManager* m_pInstance;
	LogManager();
public:
	void Initialize(std::string& logFileName);
	void Shutdown();

	void LogInformation(std::string& message, ...);
	void LogDebug(std::string& message, ...);
	void LogWarning(std::string& message, ...);
	void LogError(std::string& message, ...);
	void LogVerbose(std::string& message, ...);
	
	static LogManager* getInstance();
	~LogManager();
};
}

