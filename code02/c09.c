//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

#include <stdio.h>

/*下面程序的功能是从字符数组s中删除存放在c中的字符。*/

int main() {

    char s[80], c;

    int j, k;

    printf("\nEnter a string: ");

    gets(s);

    printf("\nEnter a character: ");

    c = getchar();

    for (j = k = 0; s[j] != '\0'; j++) {

        if (s[j] != c) {

            s[k++] = s[j];
        }
    }

    s[k] = '\0';

    printf("\n%s", s);

    return 0;

}