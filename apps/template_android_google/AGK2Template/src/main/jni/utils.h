#ifndef ARTRIX_H
#define ARTRIX_H
#include <android/log.h>

#define ALOGI(h, ...) ((void)__android_log_print(ANDROID_LOG_INFO, h, __VA_ARGS__))
#define ALOGW(h, ...) ((void)__android_log_print(ANDROID_LOG_WARN, h, __VA_ARGS__))
#define ALOGE(h, ...) ((void)__android_log_print(ANDROID_LOG_ERROR, h, __VA_ARGS__))
#define ALOGD(h, ...) ((void)__android_log_print(ANDROID_LOG_DEBUG, h, __VA_ARGS__))

#endif
