//
// Created by Major on 2018/12/22 22:25.
//

// �ṹ���붯̬�ڴ����

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
    // ��ֵ
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

// typedef ����ȡ����
typedef  int Age;
typedef int* AP;
typedef struct Man* MP;
typedef struct  Man man;
//typedef struct Man man, *MP;

typedef struct Woman{
    char name[20];
    int age;
} W, *WP; // W Ϊ Woman �ṹ��ı�������Ϊ�ṹ��ǰ����� typedef; *WP Ϊ Woman �ṹ��ָ��ı���


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

// �ṹ�庯��ָ���Ա
typedef struct Girl{
    char *name;
    int age;
    // ����ָ��
    void (*sayHi) (char*);
} Girl, *GirlP;

void sayHi(char* text){
    MessageBox(0, text, "����", 0);
}

// ����
void rename_1(GirlP gp){
     gp->name = "lili";
}

void method3(){
//    struct Girl gl;
    Girl gl; // ʹ�ñ���������д struct �ؼ���
    gl.name = "Lucy";
    gl.age = 18;
    gl.sayHi = sayHi;

    gl.sayHi("hello");
    GirlP gp = &gl;

    printf("%s, %d\n", gp->name, gp->age);
    // ����ָ��
    rename_1(gp);
    printf("%s, %d\n", gp->name, gp->age);

    gp->sayHi("i am lucy");

}


void main(){
//    method1();
//    method2();
    method3();

}