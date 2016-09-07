@echo off

set NDKBUILDCMD="C:\android-ndk-r12b\ndk-build.cmd"
set NDK_PROJECT_PATH="E:\testarea\artrix\apps\template_android_google\AGK2Template\src\main"
call %NDKBUILDCMD% NDK_OUT=../../build/jniObjs NDK_LIBS_OUT=./jniLibs 2> log.txt

pause
