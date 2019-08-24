//
// Created by Major on 2018/12/23 0:08.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// io ����

// ��ȡ�ı��ļ�
void method() {
    char path[] = "F:\\tmp\\test.txt";
    // ��
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�errno = %d\n", errno);
        return;
    }

    // ��ȡ
    char buff[50];
    while (fgets(buff, 50, fp)) {
        printf("%s", buff);
    }

    // �ر�
    fclose(fp);
    fp = NULL;
}

// д�ļ�
void method1(){
    char *path = "F:\\tmp\\test.txt";
    FILE *fp = fopen(path, "a"); // w ��д�� a ׷��
    char *text = "����һ������";
    int i = fputs(text, fp);
    printf("%d", i);

    fclose(fp);
}

// ��������
// C���Զ�д�ı��ļ���������ļ��Ĳ����������ڻس����з�
// д�ļ�ʱ��ÿ����һ�� '\n'���Ὣ��ת���� '\r\n'���س����У�
// ���ı�ʱ��ÿ����һ�� '\n'���Ὣ��ת���� '\n'
void method2(){
    char *read_path = "F:\\tmp\\test.txt";
    char *write_path = "F:\\tmp\\test-write.txt";
    FILE *read_fp = fopen(read_path, "rb");
    char *text = "";
    FILE *write_fp = fopen(write_path, "wb");

    // ����
    int buff[50];
    int len = 0;
    while((len = fread(buff, sizeof(int), 50, read_fp)) != 0){
        fwrite(buff, sizeof(int), len, write_fp);
    }

    fclose(read_fp);
    fclose(write_fp);

}

// ��ȡ�ļ���С
void method3(){
    char *read_path = "F:\\tmp\\test.txt";
    FILE *fp = fopen(read_path, "rb");
    int rst = fseek(fp, 0, SEEK_END);
    // ftell ���ص�ǰ���ļ�ָ��������ļ���ͷ��λ����
    long filesize = ftell(fp);
    printf("%d\n", filesize);
}


// �ı��ļ����ܡ�����
void crypt(char normal_path[], char crypt_path[]) {
    FILE *normal_fp = fopen(normal_path, "r");
    FILE *crypt_fp = fopen(crypt_path, "w");
    // һ�ζ�ȡһ���ַ�
    int ch;
    while((ch = fgetc(normal_fp) != EOF)){
        // ��� ��ͬΪ0����ͬΪ1
        fputc(ch ^ 9, crypt_fp);
    }

    fclose(normal_fp);
    fclose(crypt_fp);
}

void dcrypt(char crypt_path[], char normal_path[]) {
    FILE *normal_fp = fopen(normal_path, "r");
    FILE *crypt_fp = fopen(crypt_path, "w");
    // һ�ζ�ȡһ���ַ�
    int ch;
    while((ch = fgetc(normal_fp) != EOF)){
        // ��� ��ͬΪ0����ͬΪ1
        fputc(ch ^ 9, crypt_fp);
    }

    fclose(normal_fp);
    fclose(crypt_fp);
}

// �������ļ��ӽ���
void cryptFile(char normal_path[], char crypt_path[],char password[]) {
    FILE *normal_fp = fopen(normal_path, "rb");
    FILE *crypt_fp = fopen(crypt_path, "wb");
    // һ�ζ�ȡһ���ַ�
    int ch;
    int i = 0;
    int pwd_len = strlen(password);
    while((ch = fgetc(normal_fp) != EOF)){
        // ��� ��ͬΪ0����ͬΪ1
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
