//
// File: c04.c
// Created by Major on 2019/10/7 20:32.
//
#include <stdio.h>
#include <malloc.h>

/*通过键盘输入3名学生4门课程的成绩，

 分别求每个学生的平均成绩和每门课程的平均成绩。
要求所有成绩均放入一个4行5列的数组中，输入时同一人数据间用空格,不同人用回车
其中最后一列和最后一行分别放每个学生的平均成绩、每门课程的平均成绩及班级总平均分。*/

void func1() {
    char array[100];

    printf("please input the string: \n");

    gets(array);

    printf("input: %s\n", array);
}

void func2(){
    char *str = malloc(100);

    printf("input your words:\n");
    gets(str);

    printf("input %s", str);

    free(str);
}

int main() {
    float a[4][5], sum1, sum2;

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        sum1 = 0;
        for (j = 0; j < 4; j++) {
            sum1 += a[i][j];
        }

        a[i][4] = sum1 / 4;
    }

    for (j = 0; j < 5; j++) {
        sum2 = 0;
        for (i = 0; i < 3; i++) {
            sum2 += a[i][j];
        }

        a[3][j] = sum2 / 3;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("%6.2f", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}