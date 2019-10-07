//
// File: c06.c
// Created by Major on 2019/10/7 20:32.
//
#include <stdio.h>

/*编程打印直角杨辉三角形*/
int main() {
    int a[6][6];

    for (int i = 0; i <= 5; i++) {
        a[i][i] = 1;
        a[i][0] = 1;
    }

    for (int i = 2; i <= 5; i++) {
        for (int j = 1; j <= i - 1; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }

    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%4d", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}