//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*已知数组a中的元素已按由小到大顺序排列，以下程序的功能是将输入的一个数插入数组a中，插入后，数组a中的元素仍然由小到大顺序排列*/
#include <stdio.h>

int main() {

    int a[10] = {0, 12, 17, 20, 25, 28, 30};       /*a[0]为工作单元，从a[1]开始存放数据*/
    int x, i, j = 6;                         /*j为元素个数*/

    printf("Enter a number: ");

    scanf("%d", &x);
    a[0] = x;
    i = j;                              /*从最后一个单元开始*/
    while (a[i] > x) {
        a[i + 1] = a[i];
        i--;
    }  /*将比x大的数往后移动一个位置*/

    a[++i] = x;
    j++;                       /*插入x后元素总个数增加*/
    for (i = 1; i <= j; i++) printf("%8d", a[i]);

    printf("\n");

    return 0;
}