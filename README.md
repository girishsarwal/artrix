# Artrix

Artrix is a front end for gt-jtx m32 rc transmitter system

# Build Instructions

Building on Windows

* Download Android Studio
* Download Android NDK. Unzip in C:. Artix uses Android NDK 12b
* Add NDK location to path variable
* Goto file makefile and change NDK path (step 2) and project folder (apps\template_android_google\AGK2Template\src\main\)
* run make
* Fire up Android Studio and import the project from folder apps\template_android_google\AGK2Template\src\main\
* Hit Build and install the APK


Building on Linux

* get gcc, freeglut3
* download latest version of Android NDK. Install
* copy makefile.linux to makefile
* edit makefile and set path to ndk-build
* run make
* run ./gradlew from the root of project
* install the .apk on your android phone
