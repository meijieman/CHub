//
// Created by Major on 2018/12/23 19:50.
//

#include <stdio.h>

/*
C语言执行流程
1. 编译： 目标代码 .obj
2. 连接：目标代码与C函数连接合并，形成最终的可执行文件
3. 执行

预编译(预处理) 为编译做准备工作，完成代码文本的替换工作

 */

/*
 * define 指令
 * 1. 定义标示
 *  #ifdef __cplusplus 标识支持 C++语法
 *  防止文件重复引入
 * 2. 定义常数
 * 3. 定义宏函数
 */

void printfA(){
    printf("print A\n");
}

// 定义常数
#define MAX 100

void com_jni_read(){
    printf("read\n");
}

void com_jni_write( ){
    printf("write\n");
}

// 定义宏函数 NAME 是参数
#define jni(NAME) com_jni_##NAME();

// 使用宏函数缩短函数名称

//// 日志输出
//// __VA_ARGS__ 可变参数
//#define LOG(FORMAT, ...) printf(FORMAT, __VA_ARGS__);
//
//// 日志输出级别
//#define LOG_I(FORMAT, ...) printf("INFO:"); printf(FORMAT, __VA_ARGS__);
//#define LOG_E(FORMAT, ...) printf("ERROR:"); printf(FORMAT, __VA_ARGS__);

// 升级版
#define LOG(LEVEL, FORMAT, ...) printf(LEVEL); printf(FORMAT, __VA_ARGS__);
#define LOG_I(FORMAT, ...) LOG("INFO", FORMAT, __VA_ARGS__);
#define LOG_E(FORMAT, ...) LOG("ERROR", FORMAT, __VA_ARGS__);
#define LOG_W(FORMAT, ...) LOG("WARN", FORMAT, __VA_ARGS__);

//Android
//#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);
//LOGI("%s","fix");
//替换
//__android_log_print(ANDROID_LOG_INFO, "jason", "%s", "fix");

int main(){

    #include "my.txt"

    printfA();

    int i = 90;
    if(i < MAX){
        printf("比 max 小\n");
    }

    jni(read);
    jni(write);

//    LOG("%s%d\n", "大小", 88);
    LOG_I("%s%d\n", "重量：", 140);
    LOG_E("%s%d\n", "出错：", 110);



    return 0;
}