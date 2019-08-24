//
// Created by Major on 2018/12/23 23:03.
//
#include <stdio.h>

// JNIEnv 是结构体的指针别名
typedef struct JNINativeInterface_* JNIEnv;

// 结构体
struct JNINativeInterface_ {
    char * (*NewStringUTF) (JNIEnv*, char*);
};

char* NewStringUTF(JNIEnv* env, char* str){
    return str;
}

int main(){
    // 实例化结构体
    struct JNINativeInterface_ struct_env;
    struct_env.NewStringUTF = NewStringUTF;

    // 结构体指针
    JNIEnv e = & struct_env;

    // 结构体二级指针
    JNIEnv *env = &e;

    char *str = (*env) -> NewStringUTF(env, "abc");

    printf("%s\n", str);
    return 0;
}