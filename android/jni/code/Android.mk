LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := unicpatch
LOCAL_LDLIBS := \
        -llog \
        -lz \
        -lm \


LOCAL_SRC_FILES := \
        $(LOCAL_PATH)/randtable.c \
        $(LOCAL_PATH)/decompress.c \
        $(LOCAL_PATH)/main_wrap.cpp \
        $(LOCAL_PATH)/bzlib.c \
        $(LOCAL_PATH)/bspatch.c \
        $(LOCAL_PATH)/bzip2.c \
        $(LOCAL_PATH)/blocksort.c \
        $(LOCAL_PATH)/crctable.c \
        $(LOCAL_PATH)/compress.c \
        $(LOCAL_PATH)/huffman.c \
        
LOCAL_C_INCLUDES += $(LOCAL_PATH)

include $(BUILD_SHARED_LIBRARY)
