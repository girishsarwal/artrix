# The ARMv7 is significanly faster due to the use of the hardware FPU
APP_ABI := armeabi armeabi-v7a x86
APP_PLATFORM := android-9
APP_OPTIM := release
APP_MODULES := tinyxml2 android_player
APP_STL := stlport_static
NDK_TOOLCHAIN_VERSION := clang