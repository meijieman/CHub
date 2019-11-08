//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*用指针变量输出结构体数组元素。*/
#include <stdio.h>

struct student {
    int num;
    char *name;
    char sex;
    int age;
} stu[5] = {{1001, "lihua",    'F', 18},
            {1002, "liuxing",  'M', 19},
            {1003, "huangke",  'F', 19},
            {1004, "fengshou", 'F', 19},
            {1005, "Wangming", 'M', 18}};


int main() {
    int i;

    struct student *ps;

    printf("Num \tName\t\t\tSex\tAge\t\n");

    /*用指针变量输出结构体数组元素。*/
    for (ps = stu; ps < stu + 5; ps++)
        printf("%d\t%-10s\t\t%c\t%d\t\n", ps->num, ps->name, ps->sex, ps->age);

    printf("\n");

    /*用数组下标法输出结构体数组元素学号和年龄。*/
    for (i = 0; i < 5; i++)
        printf("%d\t%d\t\n", stu[i].num, stu[i].age);


    return 0;
}