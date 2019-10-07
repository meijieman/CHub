//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//
#include <stdio.h>

/*完善程序，实现将输入的字符串反序输出，

如输入windows 输出swodniw。*/

#include <string.h>
#include <stdlib.h>

void invert(char *s) {
    int i, j, k;

    char t;

    k = strlen(s);

    for (i = 0, j = k - 1; i < k / 2; i++, j--) {
        t = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = t;
    }
}

void func2() {
    FILE *fp;
    char str[200], *p, i, j;
    if ((fp = fopen("p9_2.out", "w")) == NULL) {
        printf("cannot open the file\n");

        // exit(0);退出程序 包含在#include <conio.h> #include <stdlib.h>

        exit(0);
    }

    printf("input str:\n");
    gets(str);

    printf("\n%s", str);
    fprintf(fp, "%s", str);

    invert(str);

    printf("\n%s", str);
    fprintf(fp, "\n%s", str);

    fclose(fp);
}

void main() {
    char c[200], c1;

    int i, j, k;

    printf("Enter a string: ");

    scanf("%s", c);

    k = strlen(c);

    for (i = 0, j = k - 1; i < k / 2; i++, j--) {
        c1 = c[i];
        c[i] = c[j];
        c[j] = c1;
    }

    printf("%s\n", c);

}