LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := zbar_static
LOCAL_MODULE_FILENAME := zbar
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libzbar.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include
LOCAL_STATIC_LIBRARIES += iconv_static
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)

LOCAL_MODULE := iconv_static
LOCAL_MODULE_FILENAME := crypto
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libiconv.a
include $(PREBUILT_STATIC_LIBRARY)
