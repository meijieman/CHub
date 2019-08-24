//
// Created by Major on 2018/12/22 21:45.
//

#include <stdio.h>

// 结构体与指针
struct Man{
    char name[20];
    int age;
};

void method1(){
    struct Man m1 = {"jack", 30};
    struct  Man *p = &m1;
    printf("%s, %d\n", m1.name, m1.age);
    printf("%s, %d\n", (*p).name, (*p).age);
    // -> 是 (*p). 的简写
    printf("%s, %d\n", p->name, p->age);

}

// 指针与结构体数组
void method2(){
    struct Man mans[] = {{"jack", 20}, {"rose", 19}};
    // 遍历数组
    struct Man *p = mans;
    for (; p < mans + 2; p++) {
        printf("%s, %d\n", p->name, p->age);
    }

    int i = 0;
    for (; i < sizeof(mans) / sizeof(struct Man); i++) {
        printf("%s, %d\n", mans[i].name, mans[i].age);
    }
}

// 结构体的大小 （字节对齐）
struct Man1{
    int age;
    double weight;
};

void method3(){
    struct Man1 m1 = {20, 89.0};
    printf("%#x, %d\n", &m1, sizeof(m1)); // 16

    /*
     结构体变量的大小，必须是最宽基本类型数据的整数倍 -> 提升内存读取效率
     （int）4 +(double) 8 = 12 需要对齐到最宽的数据类型的整数倍，即需要对齐到 double 的整数倍，则为 16


     */
}


int main(){
//    method1();
//    method2();
    method3();

    return 0;
}
