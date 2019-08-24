//
// Created by Major on 2018/12/21 22:43.
//

#include <stdio.h>
#include <stdlib.h>

void method1() {
    printf("Hello, World!\n");
//    system("mspaint");
    system("pause"); // 调用 win 系统命令
}

void method2() {
    int i = 1;
    printf("%d\n", i);
    float f = 23.4;
    printf("%f\n", f);
    short s = 2;
    printf("%d\n", s);

    /*
     基本数据类型
     int %d
     short %d
     long %ld
     float %f
     double %lf
     char %c
     %x 十六进制
     %o 八进制
     %s 字符串
     */

//    printf("int 占%d字节\n", sizeof(int));
    printf("int have %d byte\n", sizeof(int)); // 字节数跟系统有关
    printf("char have %d byte\n", sizeof(char));
    printf("float have %d byte\n", sizeof(float));


    // 等待输入
    getchar();
}

void method3() {
    // c99 才能在 for 中定义变量
    for (int n = 0; n < 10; n++) {
        printf("%d \n", n);
    }

    printf("------------\n");

    // 标准写法
    int m = 0;
    for (; m < 3; m++) {
        printf("%d\n", m);
    }

}

void method4() {
    // 输入输出
    int i;
    printf("请输入一个整数:");
    scanf("%d", &i); // & 取地址符

    printf("i 的值为 %d\n", i);
}

void method5() {
    int i = 90;
    int *p = &i; // p 的值就是 i 变量的内存地址
    printf("%#x\n", p);

    float f = 89.5f;
    printf("%f\n", f);
    float *pf = &f; // 创建一个 float 类型的指针
    printf("%#x\n", pf);

}

// 值复制
void change(int i){
    i = 300;
}

// 需要修改传入的参数，则需要使用指针
void change2(int *p){
    *p = 300; // *p = *(&i)
}

void method6() {
    int i = 90;
    printf("i 的值为 %d\n", i);
    int *p = &i; // p 是一个变量，值为 i 的内存地址
    printf("i 的地址 %#x, p 的地址 %#x\n", &i, &p);
    printf("p 的值为 %#x\n", p);
    // 间接赋值
    * p = 200;
    printf("i 的值为 %d\n", i);
//    change(i);
//    change2(p);
    change2(&i);
    printf("i 的值为 %d\n", i);
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

