//
// Created by Major on 2018/12/22 0:11.
//
#include <stdio.h>
#include <stdlib.h>


void method1() {
    int i = 89;
    int *p = &i;
    double j = 78.9;
//    p = &j;
    printf("double size %d, int size %d\n", sizeof(double), sizeof(int));

    printf("%#x, %d\n", p, *p);
//    printf("%#x, %lf\n", p, *p);


}

void method2(){
    int i = 9;
    // 空指针
    int *p = NULL;

    p = &i;

    printf("%d\n", *p);

    if(p == NULL){

    }

}

void method3(){
    // 多级指针
    int a = 50;
    int *p1 = &a;
    int **p2 = &p1; // 二级指针 p2 保存的是 p1 的值

    printf("p1 的地址 %#x, p2 的值 %#x\n", p1, p2);

    printf("a 的值 %d\n", **p2);


}



void main(){
//    method1();
//    method2();
    method3();

}

