LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := openfg
LOCAL_SRC_FILES := zygisk/openfg.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/jni
LOCAL_CPPFLAGS := -std=c++17 -O2
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)
