#ifndef MAIN_H_
#define MAIN_H_

#include <jni.h>
#include <stdio.h>

#define ANDROID 1
#define CLASSNAME "unic/cicoco/patch/PatchClient"

//JavaVM* g_jvm = NULL;


extern "C" {
    jint native_applyPatch(JNIEnv *env, jobject  clazz, jstring oldPath, jstring newPath, jstring patchPath);
};

#endif
