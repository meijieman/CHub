//
// Created by Major on 2018/12/21 22:43.
//

#include <stdio.h>
#include <stdlib.h>

void method1() {
    printf("Hello, World!\n");
//    system("mspaint");
    system("pause"); // ���� win ϵͳ����
}

void method2() {
    int i = 1;
    printf("%d\n", i);
    float f = 23.4;
    printf("%f\n", f);
    short s = 2;
    printf("%d\n", s);

    /*
     ������������
     int %d
     short %d
     long %ld
     float %f
     double %lf
     char %c
     %x ʮ������
     %o �˽���
     %s �ַ���
     */

//    printf("int ռ%d�ֽ�\n", sizeof(int));
    printf("int have %d byte\n", sizeof(int)); // �ֽ�����ϵͳ�й�
    printf("char have %d byte\n", sizeof(char));
    printf("float have %d byte\n", sizeof(float));


    // �ȴ�����
    getchar();
}

void method3() {
    // c99 ������ for �ж������
    for (int n = 0; n < 10; n++) {
        printf("%d \n", n);
    }

    printf("------------\n");

    // ��׼д��
    int m = 0;
    for (; m < 3; m++) {
        printf("%d\n", m);
    }

}

void method4() {
    // �������
    int i;
    printf("������һ������:");
    scanf("%d", &i); // & ȡ��ַ��

    printf("i ��ֵΪ %d\n", i);
}

void method5() {
    int i = 90;
    int *p = &i; // p ��ֵ���� i �������ڴ��ַ
    printf("%#x\n", p);

    float f = 89.5f;
    printf("%f\n", f);
    float *pf = &f; // ����һ�� float ���͵�ָ��
    printf("%#x\n", pf);

}

// ֵ����
void change(int i){
    i = 300;
}

// ��Ҫ�޸Ĵ���Ĳ���������Ҫʹ��ָ��
void change2(int *p){
    *p = 300; // *p = *(&i)
}

void method6() {
    int i = 90;
    printf("i ��ֵΪ %d\n", i);
    int *p = &i; // p ��һ��������ֵΪ i ���ڴ��ַ
    printf("i �ĵ�ַ %#x, p �ĵ�ַ %#x\n", &i, &p);
    printf("p ��ֵΪ %#x\n", p);
    // ��Ӹ�ֵ
    * p = 200;
    printf("i ��ֵΪ %d\n", i);
//    change(i);
//    change2(p);
    change2(&i);
    printf("i ��ֵΪ %d\n", i);
}



int main() {
//    method1();
//    method2();
//    method3();
//    method4();
//    method5();
    method6();
}


//int main(int argc, char** argv){
//
//    return 0;
//}

