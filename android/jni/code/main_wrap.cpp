#include "main_wrap.h"
#include "uniclog.h"
#include "bspatch.h"

static JNINativeMethod g_methods[] = {

{ "applyPatch2APK", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I",
		(void*) native_applyPatch }, };

int registerNatives(JNIEnv* env, jclass clazz, JNINativeMethod *methods,
		int numMethods) {
	if (env->RegisterNatives(clazz, methods, numMethods) < 0) {
		return -1;
	}

	return 0;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	LOGI("JNI_OnLoad...");
	//	g_jvm = vm; // 保留全局变量
	JNIEnv* env;

	if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
		return JNI_ERR;
	}

	jclass cls = env->FindClass(CLASSNAME);
	if (NULL == cls) {
		return JNI_ERR;
	}
	if (registerNatives(env, cls, g_methods,
			sizeof(g_methods) / sizeof(g_methods[0])) < 0) {
		LOGE("register natives failed");
		return JNI_ERR;
	}

	return JNI_VERSION_1_4;
}

void JNI_OnUnload(JavaVM *vm, void *reserved) {
}

jint native_applyPatch(JNIEnv *env, jobject clazz, jstring oldPath,
		jstring newPath, jstring patchPath) {
	int argc = 4;
	char * argv[argc];
	argv[0] = "bspatch";
	argv[1] = (char*) (env->GetStringUTFChars(oldPath, 0));
	argv[2] = (char*) (env->GetStringUTFChars(newPath, 0));
	argv[3] = (char*) (env->GetStringUTFChars(patchPath, 0));

	int ret = applyPatch(argc, argv, env);

	env->ReleaseStringUTFChars(oldPath, argv[1]);
	env->ReleaseStringUTFChars(oldPath, argv[2]);
	env->ReleaseStringUTFChars(oldPath, argv[3]);
	return ret;
}
