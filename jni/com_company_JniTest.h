/* DO NOT EDIT THIS FILE - it is machine generated */
#include "jni.h"
/* Header for class com_company_JniTest */

#ifndef _Included_com_company_JniTest
#define _Included_com_company_JniTest
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_company_JniTest
 * Method:    getStringFromC
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_company_JniTest_getStringFromC
        (JNIEnv *, jclass);

/*
 * Class:     com_company_JniTest
 * Method:    getString2FromC
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_company_JniTest_getString2FromC
        (JNIEnv *, jobject, jint);

/*
 * Class:     com_company_JniTest
 * Method:    accessField
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_company_JniTest_accessField
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    accessStaticField
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_accessStaticField
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    accessMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_accessMethod
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    accessStaticMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_accessStaticMethod
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    accessConstructor
 * Signature: ()Ljava/util/Date;
 */
JNIEXPORT jobject JNICALL Java_com_company_JniTest_accessConstructor
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    accessNonvirtualMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_accessNonvirtualMethod
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    chineseChars
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_company_JniTest_chineseChars
        (JNIEnv *, jobject, jstring);

/*
 * Class:     com_company_JniTest
 * Method:    giveArray
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_giveArray
        (JNIEnv *, jobject, jintArray);


/*
 * Class:     com_company_JniTest
 * Method:    getArray
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_com_company_JniTest_getArray
        (JNIEnv *, jobject, jint);

/*
 * Class:     com_company_JniTest
 * Method:    localRef
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_localRef
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    createGlobalRef
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_createGlobalRef
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    getGlobalRef
 * Signature: ()V
 */
JNIEXPORT jstring JNICALL Java_com_company_JniTest_getGlobalRef
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    delGlobalRef
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_delGlobalRef
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    exception
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_exception
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    cached
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_cached
        (JNIEnv *, jobject);

/*
 * Class:     com_company_JniTest
 * Method:    initIds
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_company_JniTest_initIds
        (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
