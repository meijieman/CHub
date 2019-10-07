//
// File: c04.c
// Created by Major on 2019/10/7 20:32.
//
#include <stdio.h>

/*一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程
　　　找出1000以内的所有完数。*/

int main() {

    static int k[10];
    int n, s;
    for (int j = 2; j < 1000; j++) {
        n = -1;
        s = j;
        for (int i = 1; i < j; i++) {
            if (j % i == 0) {
                n++;
                s = s - i;
                k[n] = i;
            }
        }
        if (s == 0) {
            printf("%d is a perfect number: \n", j);
            for (int i = 0; i < n; i++) {
                printf("%d, ", k[i]);
            }
            printf("%d\n", k[n]);
        }
    }

    return 0;
}