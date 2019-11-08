//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//
/*建立一个有三个结点的简单链表：*/

#include <stdio.h>

#define NULL 0


struct student {
    int num;

    char *name;

    int age;

    struct student *next;
};

int main() {
    struct student a, b, c, *head, *p;

    a.num = 1001;
    a.name = "lihua";
    a.age = 18;
    /*  对结点成员进行赋值  */

    b.num = 1002;
    b.name = "liuxing";
    b.age = 19;

    c.num = 1003;
    c.name = "huangke";
    c.age = 18;
    head = &a;
    /*  建立链表，a为头结点  */
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    p = head;

    /*  输出链表  */
    do {
        printf("%5d,%s,%3d\n", p->num, p->name, p->age);
        p = p->next;
    } while (p != NULL);

    return 0;
}