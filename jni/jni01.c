//
// Created by Major on 2018/12/23 20:49.
//

#include "com_company_JniTest.h"
#include <Windows.h>

// 函数实现
JNIEXPORT jstring JNICALL Java_com_company_JniTest_getStringFromC
        (JNIEnv *env, jclass jcls) {

    // 调用 win 命令
//    WinExec("D:/Program Files (x86)/Tencent/QQ/Bin/QQScLauncher.exe", 0);

    // 将 C 的字符串转为 java 字符串
    return (*env)->NewStringUTF(env, "C String");
}

JNIEXPORT jstring JNICALL Java_com_company_JniTest_getString2FromC
        (JNIEnv *env, jobject jobj, jint ji) {
    // 静态方法入参为 jclass；非静态方法入参为 jobject，代表该方法所属对象

    return (*env)->NewStringUTF(env, "c String 2");
}

// 访问属性
JNIEXPORT jstring JNICALL Java_com_company_JniTest_accessField
        (JNIEnv *env, jobject jobj){

    jclass cls = (*env)->GetObjectClass(env, jobj);
    // 属性签名
    jfieldID fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
    if(fid == NULL){
        printf("fid is null");
    }
    jstring jstr = (*env) ->GetObjectField(env, jobj, fid);
    if(jstr == NULL){
        printf("jstr is null");
    }

    // JNI_TRUE
    // JNI_FALSE
    const char *c_str = (*env)->GetStringUTFChars(env, jstr, NULL);

    char text[20] = "super";
    strcat(text, c_str);

    jstring new_jstr = (*env)->NewStringUTF(env, text);
    // 设置修改值
    (*env)->SetObjectField(env, jobj, fid, new_jstr);

    return new_jstr;
}

// 访问静态属性
JNIEXPORT void JNICALL Java_com_company_JniTest_accessStaticField
        (JNIEnv *env, jobject jobj){
    // jclass
    jclass cls = (*env)->GetObjectClass(env, jobj);
    jfieldID  fid= (*env)->GetStaticFieldID(env, cls, "count", "I");

    jint count = (*env)->GetStaticIntField(env, cls, fid);
    count++;
    // 修改
    (*env)->SetStaticIntField(env, cls, fid, count);
}

// 访问 java 方法
JNIEXPORT void JNICALL Java_com_company_JniTest_accessMethod
        (JNIEnv *env, jobject jobj){
    jclass cls = (*env)->GetObjectClass(env, jobj);
    jmethodID mid = (*env)->GetMethodID(env, cls, "genRandomInt", "(I)I");

    jint random = (*env)->CallIntMethod(env, jobj, mid, 200);
    printf("[C]random num: %ld\n", random);
}

// 访问 java 静态方法
JNIEXPORT void JNICALL Java_com_company_JniTest_accessStaticMethod
        (JNIEnv *env, jobject jobj) {
    jclass cls = (*env)->GetObjectClass(env, jobj);
    jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUuid", "()Ljava/lang/String;");
    jstring uuid = (*env)->CallStaticObjectMethod(env, cls, mid);

    const char *uuid_str = (*env)->GetStringUTFChars(env, uuid, JNI_FALSE);
    char filename[100];
    sprintf(filename, "D://tmp/%s.txt", uuid_str);
    FILE *fp = fopen(filename, "w");
    fputs("i love hy", fp);
    fclose(fp);

}

// 访问构造方法
JNIEXPORT jobject JNICALL Java_com_company_JniTest_accessConstructor
        (JNIEnv *env, jobject jobj) {
    jclass cls = (*env)->FindClass(env, "java/util/Date");
    // 构造方法用 <init>
    jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
    if(constructor_mid == NULL){
        printf("[C]constructor_mid is NULL");
    }
    // 实例化一个 Date 对象
    jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
    jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");
    jlong time = (*env)->CallLongMethod(env, date_obj, mid);
    printf("[C]time: %lld\n", time);

    return date_obj;
}

// 调用父类的方法
JNIEXPORT void JNICALL Java_com_company_JniTest_accessNonvirtualMethod
        (JNIEnv *env, jobject jobj){
    // 虚函数

    jclass cls = (*env)->GetObjectClass(env, jobj);
    // 获取 man 属性
    jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/company/Human;");
    jobject human_obj = (*env)->GetObjectField(env, jobj, fid);

    // 注意传父类的名称
    jclass human_cls = (*env)->FindClass(env, "com/company/Human");
    jmethodID mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");
    // 执行方法
//    (*env)->CallObjectMethod(env, human_obj, mid);
    // 调用父类的方法
    (*env)->CallNonvirtualObjectMethod(env, human_obj,human_cls, mid);
}

// 中文字符，编码问题
JNIEXPORT jstring JNICALL Java_com_company_JniTest_chineseChars
        (JNIEnv *env, jobject jobj, jstring in){

    // java -> c 不会乱码？
    const char *c_str = (*env)->GetStringUTFChars(env, in, JNI_FALSE);
    printf("[C]%s\n", c_str);

    // c -> jstring
    char *c_str_1 = "梦想与坚持"; // char c_str_1[] = "梦想与坚持";
//    jstring string = (*env)->NewStringUTF(env, c_str_1);
//    return string;

    jclass str_cls = (*env)->FindClass(env, "java/lang/String");
    jmethodID constructor_mid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");
    // jbyte -> char
    jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str_1));
    // 给 bytes 赋值
    (*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str_1), c_str_1);

    // fixme 跟输出的平台有关，我的只有使用 utf8 才能正常显示
    jstring charsetName = (*env)->NewStringUTF(env, "GB2312");

    return (*env)->NewObject(env, str_cls, constructor_mid, bytes, charsetName);
}

//int compare(int *a, int *b){
//    return (*a) - (*b);
//}
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

// 数组处理
JNIEXPORT void JNICALL Java_com_company_JniTest_giveArray
        (JNIEnv *env , jobject obj, jintArray arr){

    // jintAray -> jint 指针 -> C int 数组
    jint *elems = (*env)->GetIntArrayElements(env, arr, NULL);
    int len = (*env)->GetArrayLength(env, arr);
    // 排序
    qsort(elems, len, sizeof(jint), compare);

    printf("%#x, %#x\n", &elems, &arr);
    // 同步
    // mode 0 java 数组进行更新，并且释放 C/C++ 数组；
    // JNI_ABORT java 数组不更新，但释放 C/C++ 数组；
    // JNI_COMMIT java 数组进行更新，不释放 C/C++ 数组（函数执行完，会释放）
    (*env)->ReleaseIntArrayElements(env, arr, elems, 0);
}


// 返回数组
JNIEXPORT jintArray JNICALL Java_com_company_JniTest_getArray
        (JNIEnv * env, jobject jobj, jint len){

    jintArray jint_arr = (*env)->NewIntArray(env, len);
    jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);

    int i = 0;
    for (; i < len; i++) {
        elems[i] = i;
    }

    // 同步
    (*env)->ReleaseIntArrayElements(env, jint_arr, elems, 0);

    return jint_arr;
}

// JNI 引用变量
// 引用类型：局部引用和全局引用
// 作用：在 JNI 中告知虚拟机何时回收一个 JNI 变量

// 局部引用 通过 DeleteLocalRef 手动释放对象
// 1. 访问一个很大的 java 对象，使用完之后，还要进行复杂的耗时操作
// 2. 创建了大量的局部引用，占用了太多的内存，而且这些局部引用跟后面的操作没有关联性

// 模拟循环创建数组
JNIEXPORT void JNICALL Java_com_company_JniTest_localRef
        (JNIEnv *env, jobject jobj){
    int i= 0;
    for (; i < 5; i++) {
        jclass cls = (*env)->FindClass(env, "java/util/Date");
        jmethodID constructor_mid = (*env)-> GetMethodID(env, cls, "<init>", "()V");
        jobject obj = (*env)->NewObject(env, cls, constructor_mid);
        // 对 obj 进行操作


        // 通知垃圾回收器回收对象
        (*env)-> DeleteLocalRef(env, obj);
        printf("[C]释放的编号 %d 的对象", i);

    }   
}

// 全局引用
// 1. 共享（可以多线程访问） 2. 手动控制内存使用
jstring global_str;

// 创建
JNIEXPORT void JNICALL Java_com_company_JniTest_createGlobalRef
        (JNIEnv *env, jobject jobj){
    jstring obj = (*env)->NewStringUTF(env, "jni development is powerful");
    global_str = (*env)->NewGlobalRef(env, obj);
}

// 获取
JNIEXPORT jstring JNICALL Java_com_company_JniTest_getGlobalRef
        (JNIEnv *env, jobject jobj){
    return global_str;
}

// 释放
JNIEXPORT void JNICALL Java_com_company_JniTest_delGlobalRef
        (JNIEnv *env, jobject jobj){
    (*env)->DeleteGlobalRef(env, global_str);
}

// 弱全局引用
// 在内存不足时可以释放所引用的对象
// 可以引用一个不常用的对象，如果对象为 NULL， 临时创建
// NewWeakGlobalRef, DeleteGlobalWeakRef

// 异常处理
// 1. 保证 java 代码可以运行
// 2. 保证 C 代码继续运行

// JNI 自己抛出的异常，在 Java 层无法被捕获，只能在 C 层清空
// 用户通过 ThrowNew 抛出的异常，可以在 Java 层捕获
JNIEXPORT void JNICALL Java_com_company_JniTest_exception
        (JNIEnv *env, jobject jobj){
    jclass cls = (*env)->GetObjectClass(env, jobj);
    // jobj 不存在 key2 属性
    jfieldID fid = (*env)-> GetFieldID(env, cls, "key2", "Ljava/lang/String;");
    // 检测是否发生 java 异常
    jthrowable ex = (*env)->ExceptionOccurred(env);
    if (ex != NULL) {
        // 发生异常
        // 清空异常信息，让 java 代码继续运行
        (*env)-> ExceptionClear(env);
        printf("[C]发生异常\n");

        // 如果拿不到 key2，则获取 key
        fid = (*env) -> GetFieldID(env, cls, "key", "Ljava/lang/String;");
    }

    jstring jstr = (*env)->GetObjectField(env, jobj, fid);
    const char *str = (*env)->GetStringUTFChars(env, jstr, NULL);

    // 对比属性值是否合法
    if (stricmp(str, "jason1") != 0) {
        // 不合法，抛出异常给 java 处理
        jclass newExcCls = (*env)->FindClass(env, "java/lang/IllegalAccessException");
        (*env)-> ThrowNew(env, newExcCls, "key's value is invalid.");

        printf("[C]值不相等，抛出异常\n");
    } else {
        printf("[C]值相等\n");
    }
}


// 缓存策略
// 
JNIEXPORT void JNICALL Java_com_company_JniTest_cached
        (JNIEnv *env, jobject jobj){
    jclass cls = (*env)->GetObjectClass(env, jobj);
    // 多次调用 cached，获取一次 fid
    // static 局部静态变量。 key_id 这个变量只能在 Java_com_company_JniTest_cached 方法内使用，但是其生命周期和程序的一样
    static jfieldID key_id = NULL;
    if(key_id == NULL){
        key_id = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
        printf("[C]---GetFieldID---\n");
    }
}

// 初始化全局变量
jfieldID  key_fid;
jmethodID random_mid;

JNIEXPORT void JNICALL Java_com_company_JniTest_initIds
        (JNIEnv *env, jclass jcls){
    key_fid = (*env)->GetFieldID(env, jcls, "key", "Ljava/lang/String;");
    random_mid = (*env)->GetMethodID(env, jcls, "genRandomInt", "(I)I") ;
    printf("[C]初始化全局变量\n");
}