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
    // ��ָ��
    int *p = NULL;

    p = &i;

    printf("%d\n", *p);

    if(p == NULL){

    }

}

void method3(){
    // �༶ָ��
    int a = 50;
    int *p1 = &a;
    int **p2 = &p1; // ����ָ�� p2 ������� p1 ��ֵ

    printf("p1 �ĵ�ַ %#x, p2 ��ֵ %#x\n", p1, p2);

    printf("a ��ֵ %d\n", **p2);


}



void main(){
//    method1();
//    method2();
    method3();

}

