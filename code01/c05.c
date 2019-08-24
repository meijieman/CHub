//
// Created by Major on 2018/12/22 18:24.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// 使用字符数组存储字符串
void method1(){
//    char str[] = {'c', 'h', 'i', 'n', 'a', '\0'};
//    char str[6] = {'c', 'h', 'i', 'n', 'a'};
    char str[10] = "china";
    // 可以修改
    str[0] = 's';
    printf("%s, %#x\n", str, str);

}

// 使用字符指针
void method2(){
    // 内存连续排列
    char *str = "how are you?";
//    str [0] = 'w'; // 不能修改

    printf("%s, %#x\n", str, str);

    // 使用指针加法，截取字符串
    str += 3;
    while(*str){
        printf("%c", *str);
        str++;
    }

}

void method3(){
    // strcat 字符串拼接
    char dest[50];
    char *a = "china";
    char *b = " is pwoerful!";
    strcpy(dest, a);
    strcat(dest, b);
    printf("%s\n", dest);
}

void method4() {
    // strchr 查找字符，返回查找到的字符的地址
    char *str = "I want go to USA!";
    printf("%#x\n", str);
    char *p = strchr(str, 'w');
    if (p) {
        printf("查找值 %s\n", p);
        printf("索引位置 %d\n", p - str);
    } else {
        printf("没有找到");
    }
}

void method5(){
    // strstr 查找字符串
    char *str = "no one like you";
    char *find = "like";
    char *ret = strstr(str, find);

    if(ret){
        printf("找到 %s\n", ret);
        printf("找到index %d\n", ret - str);
    } else {
        printf("未找到对应字符串");
    }


}

/*
 使用需要修改的字符串使用数组，不可修改的字符串使用指针
 */

int main(){
//    method1();
//    method2();
//    method3();
//    method4();
    method5();



    return 0;
}