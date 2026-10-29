LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := openfg_clone
LOCAL_SRC_FILES := main.cpp hooks.cpp
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv2 -ldl
LOCAL_CFLAGS := -fvisibility=default -O2
LOCAL_CPPFLAGS := -std=c++17
include $(BUILD_SHARED_LIBRARY)
