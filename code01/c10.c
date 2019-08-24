//
// Created by Major on 2018/12/22 23:46.
//
#include <stdio.h>

// 联合体（共用体）
// 不同类型的变量共同占用一段内存，联合变量任何时候只有一个成员存在
// 目的是节约内存
// 联合体变量的大小 = 最大的成员所占的字节数

union MyValue{
    int x;
    int y;
    double z;
};

void method1(){
    union  MyValue d1;
    d1.x = 90;
    d1.y = 100;
    d1.z = 23.8;

    printf("%d, %d, %lf\n", d1.x, d1.y, d1.z);

}

// 枚举
enum Day {
    Mon,
    // Mon = 0,
    Tue,
    Wed,
    Thur,
    Fir,
    Sat,
    Sun,
};

void method2(){
    enum Day d= Wed;
    printf("%#x, %d\n", &d, d);

    //fixme 枚举如何遍历？

//    int i = 0;
//    enum Day *p = &d;
//    for(; i < 7; i++){
//        printf("%#x, %d\n", p, *p);
//        p++;
//    }

}

void main(){
//    method1();
    method2();

}

