
#include "MethodExecutorJni.h"
#include "MethodResultJni.h"

#include "rhodes/JNIRhodes.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "MethodExecutorJNI"

namespace rhoelements {

const char * const MethodExecutorJni::METHOD_EXECUTOR_CLASS = "com.rhomobile.rhodes.api.MethodExecutor";

jclass MethodExecutorJni::s_MethodExecutorClass = 0;
jmethodID MethodExecutorJni::s_midRun;
jmethodID MethodExecutorJni::s_midRunWithSeparateThread;
jmethodID MethodExecutorJni::s_midRunWithUiThread;

//----------------------------------------------------------------------------------------------------------------------

JNIEnv* MethodExecutorJni::jniInit()
{
    JNIEnv *env = jnienv();
    if (!env) {
        RAWLOG_ERROR("JNI init failed: JNIEnv is null");
        return 0;
    }
    return jniInit(env);
}
//----------------------------------------------------------------------------------------------------------------------

JNIEnv* MethodExecutorJni::jniInit(JNIEnv* env)
{
    if(!s_MethodExecutorClass)
    {
        s_MethodExecutorClass = loadClass(env, METHOD_EXECUTOR_CLASS);
        if (!s_MethodExecutorClass)
            return 0;

        s_midRun = env->GetStaticMethodID(s_MethodExecutorClass, "run", "(Ljava/lang/Runnable;)V");
        if(!s_midRun)
        {
            RAWLOG_ERROR1("Failed to get method 'run' for java class %s", METHOD_EXECUTOR_CLASS);
            s_MethodExecutorClass = 0;
            return NULL;
        }
        s_midRunWithSeparateThread = env->GetStaticMethodID(s_MethodExecutorClass, "runWithSeparateThread", "(Ljava/lang/Runnable;)V");
        if(!s_midRunWithSeparateThread)
        {
            RAWLOG_ERROR1("Failed to get method 'runWithSeparateThread' for java class %s", METHOD_EXECUTOR_CLASS);
            s_MethodExecutorClass = 0;
            return NULL;
        }
        s_midRunWithUiThread = env->GetStaticMethodID(s_MethodExecutorClass, "runWithUiThread", "(Ljava/lang/Runnable;)V");
        if(!s_midRunWithUiThread)
        {
            RAWLOG_ERROR1("Failed to get method 'runWithUiThread' for java class %s", METHOD_EXECUTOR_CLASS);
            s_MethodExecutorClass = 0;
            return NULL;
        }
        RAWTRACE("MethodExecutorJni JNI init succeeded");
    }
    return env;
}
//----------------------------------------------------------------------------------------------------------------------

jclass MethodExecutorJni::loadClass(JNIEnv* env, const char* const name)
{
    jclass res = 0;
    jclass cls = rho_find_class(env, name);
    if(!cls)
    {
        RAWLOG_ERROR1("Failed to find java class: %s", name);
        return 0;
    }
    res = static_cast<jclass>(env->NewGlobalRef(cls));
    env->DeleteLocalRef(cls);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------
void MethodExecutorJni::run(JNIEnv* env, jobject jTask, MethodResultJni& result, bool thread, bool uiThread)
{
    if(uiThread)
    {
        env->CallStaticVoidMethod(s_MethodExecutorClass, s_midRunWithUiThread, jTask);
    }
    else if(result.hasCallBackUrl() || thread)
    {
        env->CallStaticVoidMethod(s_MethodExecutorClass, s_midRunWithSeparateThread, jTask);
    }
    else
    {
        env->CallStaticVoidMethod(s_MethodExecutorClass, s_midRun, jTask);
    }
}
//----------------------------------------------------------------------------------------------------------------------

}
