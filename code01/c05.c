//
// Created by Major on 2018/12/22 18:24.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// ʹ���ַ�����洢�ַ���
void method1(){
//    char str[] = {'c', 'h', 'i', 'n', 'a', '\0'};
//    char str[6] = {'c', 'h', 'i', 'n', 'a'};
    char str[10] = "china";
    // �����޸�
    str[0] = 's';
    printf("%s, %#x\n", str, str);

}

// ʹ���ַ�ָ��
void method2(){
    // �ڴ���������
    char *str = "how are you?";
//    str [0] = 'w'; // �����޸�

    printf("%s, %#x\n", str, str);

    // ʹ��ָ��ӷ�����ȡ�ַ���
    str += 3;
    while(*str){
        printf("%c", *str);
        str++;
    }

}

void method3(){
    // strcat �ַ���ƴ��
    char dest[50];
    char *a = "china";
    char *b = " is pwoerful!";
    strcpy(dest, a);
    strcat(dest, b);
    printf("%s\n", dest);
}

void method4() {
    // strchr �����ַ������ز��ҵ����ַ��ĵ�ַ
    char *str = "I want go to USA!";
    printf("%#x\n", str);
    char *p = strchr(str, 'w');
    if (p) {
        printf("����ֵ %s\n", p);
        printf("����λ�� %d\n", p - str);
    } else {
        printf("û���ҵ�");
    }
}

void method5(){
    // strstr �����ַ���
    char *str = "no one like you";
    char *find = "like";
    char *ret = strstr(str, find);

    if(ret){
        printf("�ҵ� %s\n", ret);
        printf("�ҵ�index %d\n", ret - str);
    } else {
        printf("δ�ҵ���Ӧ�ַ���");
    }


}

/*
 ʹ����Ҫ�޸ĵ��ַ���ʹ�����飬�����޸ĵ��ַ���ʹ��ָ��
 */

int main(){
//    method1();
//    method2();
//    method3();
//    method4();
    method5();



    return 0;
}