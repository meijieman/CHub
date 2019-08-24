//
// Created by Major on 2018/12/22 23:30.
//
#include <stdio.h>
#include <string.h>

struct Song{
    char name[20];
    char *singer;
} S, *SP; // S 结构体变量，SP 结构体变量指针

void method1(){
    strcpy(S.name, "Baby");
    S.singer = "Justin Biber";

    // SP 指针赋值
    SP = &S;
    printf("%s, %s\n", SP->name, SP->singer);

    printf("-------------------\n");

    // 字符数组只能在声明时赋值，如果需要重新赋值，需要使用 strcpy
    char a[10] = "my name";
    printf("%s\n", a);
//    a = "xxx";
    // 可以修改内容
    a[0] = 'y';
    printf("%s\n", a);

    // 字符指针可以重新赋值，但不能修改其中的内容
    char *b = "friend";
    b = "family";

    printf("b: %s\n", b);

}

void main(){
    method1();
}
