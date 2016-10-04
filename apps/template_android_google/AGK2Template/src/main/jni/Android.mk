# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

### copy the AGK lib into the objs directory for linking ###
include $(CLEAR_VARS)
LOCAL_MODULE    := AGKBullet
LOCAL_SRC_FILES := ../../../../../../platform/android/jni/$(TARGET_ARCH_ABI)/libAGKBullet.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../../../../common/include \
    $(LOCAL_PATH)/../../../../../../bullet \
    $(LOCAL_PATH)/../../../../../../bullet/BulletCollision/CollisionShapes
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := AGKAssimp
LOCAL_SRC_FILES := ../../../../../../platform/android/jni/$(TARGET_ARCH_ABI)/libAGKAssimp.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../../../../common/include \
    $(LOCAL_PATH)/../../../../../../bullet \
    $(LOCAL_PATH)/../../../../../../bullet/BulletCollision/CollisionShapes
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := AGKAndroid
LOCAL_SRC_FILES := ../../../../../../platform/android/jni/$(TARGET_ARCH_ABI)/libAGKAndroid.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../../../../common/include \
    $(LOCAL_PATH)/../../../../../../bullet \
    $(LOCAL_PATH)/../../../../../../bullet/BulletCollision/CollisionShapes
LOCAL_STATIC_LIBRARIES := AGKBullet AGKAssimp
include $(PREBUILT_STATIC_LIBRARY)


### extra libraries ###
include $(CLEAR_VARS)
LOCAL_MODULE    := tinyxml2
LOCAL_SRC_FILES := ../../../../../../platform/tinyxml2/source/tinyxml2.cpp
LOCAL_C_INCLUDES := ../../../../../../platform/tinyxml2/include
include $(BUILD_STATIC_LIBRARY)

### build the app ###
include $(CLEAR_VARS)

# the name of the library referenced from the AndroidManifest.xml file
LOCAL_MODULE    := android_player

# agk includes folder
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../../../common/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../platform/tinyxml2/include

# app source files, must be relative to the jni folder
LOCAL_SRC_FILES := main.c Core.cpp template.cpp \
                    Vector2.cpp MetricsManager.cpp Command.cpp ConfigurationManager.cpp StateManager.cpp Managers.cpp\
                    statemachine.cpp state.cpp artrix.cpp \
                    screen.cpp widget.cpp WidgetFactory.cpp\
                    LeafWidget.cpp CompositeWidget.cpp \
                    ButtonWidget.cpp ImageWidget.cpp MainMenuWidget.cpp TextWidget.cpp

# included system libraries
LOCAL_LDLIBS    := -lm -llog -landroid -lEGL -lGLESv2 -lz -lOpenSLES

# included user libraris
LOCAL_STATIC_LIBRARIES := AGKBullet AGKAssimp AGKAndroid tinyxml2 android_native_app_glue

# define IDE_ANDROID (for AGK) and use O3 optimizations
LOCAL_CFLAGS += -DIDE_ANDROID -O3 -fsigned-char
LOCAL_CPPFLAGS += -fexceptions

# use arm instead of thumb instructions
LOCAL_ARM_MODE := arm

include $(BUILD_SHARED_LIBRARY)

### build the native support library ###
$(call import-module,android/native_app_glue)
