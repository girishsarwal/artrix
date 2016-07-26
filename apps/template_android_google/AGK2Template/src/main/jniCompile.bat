@echo off

set NDKBUILDCMD="C:\android-ndk-r12b\ndk-build.cmd"

call %NDKBUILDCMD% NDK_OUT=../../build/jniObjs NDK_LIBS_OUT=./jniLibs 2> log.txt

pause
