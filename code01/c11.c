//
// Created by Major on 2018/12/23 0:08.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// io 操作

// 读取文本文件
void method() {
    char path[] = "F:\\tmp\\test.txt";
    // 打开
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("文件打开失败，errno = %d\n", errno);
        return;
    }

    // 读取
    char buff[50];
    while (fgets(buff, 50, fp)) {
        printf("%s", buff);
    }

    // 关闭
    fclose(fp);
    fp = NULL;
}

// 写文件
void method1(){
    char *path = "F:\\tmp\\test.txt";
    FILE *fp = fopen(path, "a"); // w 覆写， a 追加
    char *text = "新增一条数据";
    int i = fputs(text, fp);
    printf("%d", i);

    fclose(fp);
}

// 读二进制
// C语言读写文本文件与二进制文件的差别仅仅体现在回车换行符
// 写文件时，每遇到一个 '\n'，会将其转换成 '\r\n'（回车换行）
// 读文本时，每遇到一个 '\n'，会将其转换成 '\n'
void method2(){
    char *read_path = "F:\\tmp\\test.txt";
    char *write_path = "F:\\tmp\\test-write.txt";
    FILE *read_fp = fopen(read_path, "rb");
    char *text = "";
    FILE *write_fp = fopen(write_path, "wb");

    // 复制
    int buff[50];
    int len = 0;
    while((len = fread(buff, sizeof(int), 50, read_fp)) != 0){
        fwrite(buff, sizeof(int), len, write_fp);
    }

    fclose(read_fp);
    fclose(write_fp);

}

// 获取文件大小
void method3(){
    char *read_path = "F:\\tmp\\test.txt";
    FILE *fp = fopen(read_path, "rb");
    int rst = fseek(fp, 0, SEEK_END);
    // ftell 返回当前的文件指针相对于文件开头的位移量
    long filesize = ftell(fp);
    printf("%d\n", filesize);
}


// 文本文件加密、解密
void crypt(char normal_path[], char crypt_path[]) {
    FILE *normal_fp = fopen(normal_path, "r");
    FILE *crypt_fp = fopen(crypt_path, "w");
    // 一次读取一个字符
    int ch;
    while((ch = fgetc(normal_fp) != EOF)){
        // 异或 相同为0，不同为1
        fputc(ch ^ 9, crypt_fp);
    }

    fclose(normal_fp);
    fclose(crypt_fp);
}

void dcrypt(char crypt_path[], char normal_path[]) {
    FILE *normal_fp = fopen(normal_path, "r");
    FILE *crypt_fp = fopen(crypt_path, "w");
    // 一次读取一个字符
    int ch;
    while((ch = fgetc(normal_fp) != EOF)){
        // 异或 相同为0，不同为1
        fputc(ch ^ 9, crypt_fp);
    }

    fclose(normal_fp);
    fclose(crypt_fp);
}

// 二进制文件加解密
void cryptFile(char normal_path[], char crypt_path[],char password[]) {
    FILE *normal_fp = fopen(normal_path, "rb");
    FILE *crypt_fp = fopen(crypt_path, "wb");
    // 一次读取一个字符
    int ch;
    int i = 0;
    int pwd_len = strlen(password);
    while((ch = fgetc(normal_fp) != EOF)){
        // 异或 相同为0，不同为1
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }

    fclose(normal_fp);
    fclose(crypt_fp);
}



int main() {
//    method();
//    method1();
//    method2();
    method3();

    char *normal_path = "F:\\tmp\\test.txt";
    char *crypt_path = "F:\\tmp\\test-crypt.txt";
    crypt(normal_path, crypt_path);

    return 0;
}
