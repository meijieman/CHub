//
// File: c08.cpp
// Created by Major on 2019/10/7 23:16.
//

/*编写函数replace(char *s,char c1,char c2)实现将s所指向的字符串中所有字符c1用c2替换，
  字符串、字符c1和c2均在主函数中输入，将原始字符串和替换后的字符串显示在屏幕上，并输出到文件p10_2.out中*/
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>


replace(char *s, char c1, char c2) {
    while (*s != '\0') {
        if (*s == c1)
            *s = c2;
        s++;
    }
}

int main() {
    FILE *fp;
    char str[100], a, b;

    char buf[80];
    getcwd(buf, sizeof(buf)); //  取得当前的工作目录
    printf("current working directory: %s\n", buf);


    if ((fp = fopen("p10_2.out", "w")) == NULL) {
        printf("cannot open thefile\n");
        exit(0);
    }
    printf("Enter a string:\n");
    gets(str);
    printf("Enter a&&b:\n");
    scanf("%c,%c", &a, &b);
    printf("%s\n", str);
    fprintf(fp, "%s\n", str);
    replace(str, a, b);
    printf("Thenew string is----%s\n", str);
    fprintf(fp, "Thenew string is----%s\n", str);

    fclose(fp);

    return 0;
}