NDKBUILDCMD="C:\android-ndk-r12b\ndk-build.cmd"
NDK_PROJECT_PATH ="E:\testarea\artrix\apps\template_android_google\AGK2Template\src\main"
all:
	pwd; $(NDKBUILDCMD) -C $(NDK_PROJECT_PATH)
clean:
	pwd; $(NDKBUILDCMD) -C $(NDK_PROJECT_PATH) clean

.PHONY: clean
.PHONY: all