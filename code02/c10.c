//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*编写一个void sort(int *x,int n)实现将x数组中的n个数据从大到小
排序。n及数组元素在主函数中输入。将结果显示在屏幕上并输出到文件p9_1.out中
 */
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sort(int *x, int n) {
    int i, j, k, t;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++)
            if (x[j] > x[k]) k = j;
        if (k != i) {
            t = x[i];
            x[i] = x[k];
            x[k] = t;
        }
    }
}

int main() {
    FILE *fp;
    int *p, i, a[10];

    char buf[80];
    getcwd(buf,sizeof(buf));
    printf("current working directory: %s\n", buf);

    fp = fopen("p9_1.out", "w");
    p = a;
    printf("Input 10 numbers:");
    for (i = 0; i < 10; i++)
        scanf("%d", p++);
    p = a;

    sort(p, 10);

    for (; p < a + 10; p++) {
        printf("%d ", *p);
        fprintf(fp, "%d ", *p);
    }
    fclose(fp);

    system("pause");

    return 0;
}