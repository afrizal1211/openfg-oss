LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := dobby
LOCAL_SRC_FILES := third_party/dobby_src/dobby.cpp
# This is simplified - real Dobby build is complex
LOCAL_CFLAGS := -I$(LOCAL_PATH)/third_party/dobby_src
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := openfg_clone
LOCAL_SRC_FILES := main.cpp hooks.cpp hooks_vulkan.cpp config.cpp frame_processor.cpp fsr.cpp
LOCAL_STATIC_LIBRARIES := dobby
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv3 -ldl -lvulkan
LOCAL_CFLAGS := -fvisibility=default -O2 -I$(LOCAL_PATH)/third_party/dobby/include
LOCAL_CPPFLAGS := -std=c++17
include $(BUILD_SHARED_LIBRARY)
