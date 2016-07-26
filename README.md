# Artrix


# Build Instructions

Building on Windows

1. Download Android Studio
2. Download Android NDK. Unzip in C:. Artix uses Android NDK 12b
3. Add NDK location to path variable
4. Goto file apps\template_android_google\AGK2Template\src\main\jniCompile.bat and change NDK path to the the unzipped location in step 2.
5. Fire up command line and browse to folder apps\template_android_google\AGK2Template\src\main\. Run jniCompile.bat
6. Fire up Androi Studio and import the project from folder apps\template_android_google\AGK2Template\src\main\
7. Hit Build and install the APK
