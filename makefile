NDKBUILDCMD="/opt/android-ndk-r11c/ndk-build"
NDK_PROJECT_PATH ="./apps/template_android_google/AGK2Template/src/main"
all:
	pwd; $(NDKBUILDCMD) -C $(NDK_PROJECT_PATH)
clean:
	pwd; $(NDKBUILDCMD) -C $(NDK_PROJECT_PATH) clean
Debug:
	pwd; $(NDKBUILDCMD) -C $(NDK_PROJECT_PATH)
.PHONY: clean
.PHONY: all
