//
// Created by Major on 2018/12/22 22:25.
//

// 结构体与动态内存分配

#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

struct Man{
    char *name;
    int age;
};

void method1(){
    struct Man *m_p = (struct Man*) malloc(sizeof(struct Man) * 10);
    struct Man *p = m_p;
    // 赋值
    p->name = "jack";
    p->age = 20;
    p++;
    p-> name = "rose";
    p->age =  18;

    struct Man *loop_p = m_p;
    for (; loop_p < m_p + 2; loop_p++) {
        printf("%s, %d\n", loop_p->name, loop_p->age);
    }

    free(m_p);
}

// typedef 类型取别名
typedef  int Age;
typedef int* AP;
typedef struct Man* MP;
typedef struct  Man man;
//typedef struct Man man, *MP;

typedef struct Woman{
    char name[20];
    int age;
} W, *WP; // W 为 Woman 结构体的别名，因为结构体前添加了 typedef; *WP 为 Woman 结构体指针的别名


void method2(){
    Age a = 10;
    AP p = &a;
    struct Man m = {"xxx", 10};
    MP mp = &m;

    printf("%d, %#x\n", a, p);
    printf("%#x\n", mp);
    printf("%s, %d\n", mp->name, mp->age);


    W w1 = {"Rose", 20};
    WP wp1 = &w1;
    printf("%s, %d\n", w1.name, w1.age);
    printf("%s, %d\n", wp1->name, wp1->age);

}

// 结构体函数指针成员
typedef struct Girl{
    char *name;
    int age;
    // 函数指针
    void (*sayHi) (char*);
} Girl, *GirlP;

void sayHi(char* text){
    MessageBox(0, text, "标题", 0);
}

// 改名
void rename_1(GirlP gp){
     gp->name = "lili";
}

void method3(){
//    struct Girl gl;
    Girl gl; // 使用别名可以少写 struct 关键字
    gl.name = "Lucy";
    gl.age = 18;
    gl.sayHi = sayHi;

    gl.sayHi("hello");
    GirlP gp = &gl;

    printf("%s, %d\n", gp->name, gp->age);
    // 传递指针
    rename_1(gp);
    printf("%s, %d\n", gp->name, gp->age);

    gp->sayHi("i am lucy");

}


void main(){
//    method1();
//    method2();
    method3();

}