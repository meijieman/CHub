//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*
 编写函数countpi，利用公式

计算π的近似值，当某一项的值小于10-5时，认为达到精度要求，请完善函数。将结果显示在屏幕上并输出到文件p7_3.out中。
 */

#include<stdio.h>
#include <stdlib.h>

/*eps为允许误差*/
double countpi(double eps) {
    int m = 1;
    double temp = 1.0, s = 0;
    while (temp >= eps) {
        s += temp;
        temp = temp * m / (2 * m + 1);
        m++;
    }

    return (2 * s);
}

int main() {
    FILE *fp;

    double eps = 1e-5, pi;
    if ((fp = fopen("p7_3.out", "w")) == NULL) {
        printf("cannot open thefile\n");
        exit(0);
    }
    pi = countpi(eps);
    printf("pi=%lf\n", pi);

    fprintf(fp, "pi=%lf\n", pi);
    fclose(fp);

}