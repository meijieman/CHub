//
// Created by Major on 2018/12/22 16:02.
//

// 指针的运算
// 指针的运算一般在数组遍历时才有意义

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void method(){

    // 数组在内存上是线性连续的
    int ids[] = {78, 90, 23, 65, 19};

    printf("%#x\n", ids);
    printf("%#x\n", &ids);
    printf("%#x\n", &ids[0]);

    int *p = ids;
    printf("%d\n", *p);

    // 指针的加法，向前移动 sizeof（数据类型） 个字节
    p++;
    printf("%d\n", *p);
}

void method1(){
    int uids[5];
    // 通过指针赋值
    int *p = uids;
    /*int i = 0;
    for(; i < 5; i++){
        uids[i] = i;
    }*/

    int i = 0;
    for(; p < uids + 5; p++){
        *p = i;
//        i++;
        i+=2;
    }

    int j = 0;
    for(; j < 5; j++){
        printf(" 第%d 对应的值为 %d\n", j, uids[j]);
    }
}

/*
 c 语言内存分配
 1. 栈区 stack
    windows 的栈内存分配 2M
    栈内存是自动分配，释放
 2. 堆区 heap
    手动分配，手动释放，可以占用操作系统 80% 的内存
 3. 全局区或静态区
 4. 字符常量区
 5. 程序代码区
 */
void method2(){
    // 40M
    int a[1024 * 1024 * 10]; // 会导致 stack overflow

}

// 堆内存 动态内存分配
void method3(){

    // malloc 传入的是字节
    // 分配 40M 的内存
    int *p = malloc(1024 * 1024 * 10 * sizeof(int));
    // malloc 返回的为 void *，表示为任意类型的指针。
    float *p1 = malloc(1024 * 1024 * 10 * sizeof(int));

    free(p); // 释放内存
    free(p1);


    getchar();
}

void method4(){
   // 创建一个数组，动态指定数组大小
   // 静态内存分配创建数组，数组的大小是固定的
//   int a[10];

    int len;
    printf("输入数组的长度：");
    scanf("%d", &len);

    // 开辟内存
    int *p = malloc(len * sizeof(int));
    // 赋值
    int i = 0;
    for (; i < len; i++) {
        p[i] = rand() % 100; // 没有给种子的随机数，每次生成的是相同的
        printf("%d, %#x\n", p[i], &p[i]);
    }

    // 释放内存
    free(p);
}

/*
  realloc 重新分配内存
  1. 缩小
  2. 扩大 （连续的）
    如果当前内存后有足够的需要的内存空间，直接扩展这段内存空间， realloc 返回原来的指针
    如果当前内存后没有足够的内存空间，使用堆中第一个满足要求的内存块，将当前数据复制到新的内存块，释放之前的内存块， realloc 返回新的指针
    申请失败，返回 NULL，原来的指针仍然有效
 */

void method5(){
    int len;
    printf("第一次输入数组的长度: ");
    scanf("%d", &len);

    int *p = malloc(len * sizeof(int));
//    int *p = calloc(len, sizeof(int));

    int i = 0;
    for (; i < len; i++) {
        p[i] = rand() % 100;
        printf("%d, %#x\n", p[i], &p[i]);
    }

    int addLen;
    printf("输入数组增加的长度：");
    scanf("%d", &addLen);
    // 扩大内存空间
    int *p2 = realloc(p, sizeof(int) * (len + addLen));

    if (p2 == NULL) {
        printf("申请内存分配失败");
    }

    // 赋值
    i = 0;
    for (; i < len + addLen; i++) {
        p2[i] = rand() % 200;

        printf("%d, %#x\n", p2[i], &p2[i]);
    }

    // p 会自动释放
//    if (p != NULL) {
//        free(p);
//        p = NULL;
//    }

    if(p2 != NULL){
        free(p2);
        p2 = NULL;
    }
}


/*
 内存分配注意事项
  1. 不能多次释放
  2. 释放完后给指针置 NULL
  3. 内存泄漏（p 重新赋值之后再 free，并没有真正释放内存）
 */
void method6(){

    int len;
    printf("输入数组的长度：");
    scanf("%d", &len);

    int *p = malloc(len * sizeof(int));
    int i = 0;
    for(; i < len; i++){
        p[i] = rand() * 200;
        printf("%d, %#x\n", p[i], &p[i]);
    }

    if(p != NULL){
        free(p);
        p = NULL;
    }
}

void method7(){
    int *p1 = malloc(1024 * 1024 * 10 * sizeof(int));
    free(p1); // 如果没有这行，则会存在内存泄漏
    printf("%#x\n", p1); // p1 free 后不会为 NULL，需要手动调用
    p1 = NULL;

    p1 = malloc(1024 * 1024 * 10 * sizeof(int) * 2);
    free(p1);
    p1 = NULL;
}


int main(){

//    method();
//    method1();
//    method2();
//    method3();
//    method4();
//    method5();
//    method6();
    method7();


    return 0;
}