//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*输入一个字符串，判断其是否为回文。回文字符串是指从左到右读和从右到左读完全相同的字符串。*/
#include<stdio.h>
#include<string.h>
#include<string.h>

int main() {
    char s[100];
    int i, j, n;
    printf("输入字符串：\n");
    gets(s);
    n = strlen(s);
    for (i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] != s[j]) break;
    if (i >= j)
        printf("是回文串\n");
    else
        printf("不是回文串\n");

    return 0;
}