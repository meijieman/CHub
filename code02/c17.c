//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*冒泡排序，从小到大，排序后结果输出到屏幕及文件myf2.out*/

#include<stdio.h>

void fun(int a[], int n) {
    int i, j, t;
    for (i = 0; i <= n - 1; i++)
        for (j = 0; j < i; j++)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main() {
    int a[10] = {12, 45, 7, 8, 96, 4, 10, 48, 2, 46}, n = 10, i;
    FILE *f;
    if ((f = fopen("myf2.out", "w")) == NULL)
        printf("open file myf2.outfailed!\n");
    fun(a, 10);
    for (i = 0; i < 10; i++) {
        printf("%4d", a[i]);
        fprintf(f, "%4d", a[i]);
    }
    fclose(f);

    return 0;
}