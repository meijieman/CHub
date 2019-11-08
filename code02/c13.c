//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

#include <stdio.h>
#include <string.h>

/*在一个字串s1中查找一子串s2，若存在则返回子串在主串中的起始位置
，不存在则返回-1。*/

int search();

char s1[6] = "thi sis";

int main() {
    char s2[5] = "is";
    printf("%d\n", search(s1, s2));

    return 0;
}

int search(char s1[], char s2[]) {
    int i = 0, j, len = strlen(s2);
    while (s1[i]) {
        for (j = 0; j < len; j++)
            if (s1[i + j] != s2[j]) break;
        if (j >= len)return i;
        else i++;
    }

    return -1;
}
