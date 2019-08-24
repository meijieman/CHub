//
// Created by Major on 2018/12/22 21:07.
//

#include <stdio.h>
#include <string.h>

// 结构体
// 结构体是一种构造数据类型，把不同的数据类型整合起来称为一个自定义的数据类型
struct Man{
    // 成员
//    char name[20];
    char * name;
    int age;
//    int (*func)(); // 函数指针
};

void method1(){
    // 初始化结构体的变量
    struct Man m1 = {"Jack", 21};
    struct Man m2;
    m2.age = 23;
//    strcpy(m2.name, "aaa");
//    sprintf(m1.name, "JSON");
    m2.name = "Rose";
    printf("%s, %d\n", m1.name, m1.age);
    printf("%s, %d\n", m2.name, m2.age);

}


//=====================
// 结构体的几种写法
struct Man1{
    char name[20];
    int age;
} m2, m3 = {"major", 26}; // m2 表示结构体的变量的名称


typedef int Age; // 取别名，将 int 取个别名为 Age


void method2(){
    Age a = 8;

    m2.age = 200;
    strcpy(m2.name, "jack");

    printf("%s, %d\n", m2.name, m2.age);
    printf("%s, %d\n", m3.name, m3.age);
}

// 匿名结构体
// 主要用于控制结构体变量的个数，定义多少个就能使用多少个
struct {
    char name[20];
    int age;
} m4, m5;

// 结构体嵌套
struct Teacher{
    char name[20];

};

struct  Student{
    char name[20];
    int age;
    struct Teacher t;
};

void method3(){
    struct Student s1 = {"jack", 21, {"jason"}};
    struct Student s2;
    s2.age = 10;
    strcpy(s2.t.name, "Jason");
}

struct Stud{
    char name[20];
    int age;
    struct  Teach{
        char name[20];
    } t;
};

void method4() {
    struct Stud s1;
    s1.age = 8;
    strcpy(s1.t.name, "jason");
    printf("%s %d\n", s1.t.name, s1.age);

    // 可以直接使用
    struct Teach t;
    strcpy(t.name, "xxx");

}



int main(){

//    method1();
//    method2();
//    method3();
    method4();


    return 0;
}

