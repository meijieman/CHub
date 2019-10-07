//
// File: c01.c
// Created by Major on 2019/10/7 19:38.
//
/*
 * C语言必背18个经典程序
 *
 */

/*输出9*9口诀。共9行9列，i控制行，j控制列。*/
#include <stdio.h>

void func1();

void func2();

int main() {

//    func1();

    func2();

    return 0;
}

void func2() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d * %d = %-3d", j, i, i * j);
        }

        printf("\r\n");

    }
}

void func1() {
    for (int i = 1; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            // -3d表示左对齐，占3位
            printf("%d * %d = %-3d", i, j, i * j);
        }
        printf("\r\n");
    }
}