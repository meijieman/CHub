//
// File: c05.c
// Created by Major on 2019/10/7 20:32.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func1();

void func2();

/*下面程序的功能是将一个4×4的数组进行逆时针旋转90度后输出，要求原始数组的数据随机输入，新数组以4行4列的方式输出，

请在空白处完善程序。*/

int main() {

    func2();

    return 0;
}

void func1() {
    int a[4][4], b[4][4]; /*a存放原始数组数据，b存放旋转后数组数据*/

    printf("input 16 numbers: ");

    /*输入一组数据存放到数组a中，然后旋转存放到b数组中*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);

            b[3 - j][i] = a[i][j];
        }
    }

    printf("array b:\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%6d", b[i][j]);
        }

        printf("\n");
    }
}

void func2() {
    int a[4][4], b[4][4];
    // 设置种子
    srand(time(NULL));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i][j] = rand() % 100;

            // 旋转的算法
            b[3 - j][i] = a[i][j];
        }
    }

    printf("array a:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%6d", a[i][j]);
        }

        printf("\n");
    }

    printf("array b:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%6d", b[i][j]);
        }

        printf("\n");
    }

}