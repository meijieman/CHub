//
// Created by Major on 2018/12/23 19:50.
//

#include <stdio.h>

/*
C����ִ������
1. ���룺 Ŀ����� .obj
2. ���ӣ�Ŀ�������C�������Ӻϲ����γ����յĿ�ִ���ļ�
3. ִ��

Ԥ����(Ԥ����) Ϊ������׼����������ɴ����ı����滻����

 */

/*
 * define ָ��
 * 1. �����ʾ
 *  #ifdef __cplusplus ��ʶ֧�� C++�﷨
 *  ��ֹ�ļ��ظ�����
 * 2. ���峣��
 * 3. ����꺯��
 */

void printfA(){
    printf("print A\n");
}

// ���峣��
#define MAX 100

void com_jni_read(){
    printf("read\n");
}

void com_jni_write( ){
    printf("write\n");
}

// ����꺯�� NAME �ǲ���
#define jni(NAME) com_jni_##NAME();

// ʹ�ú꺯�����̺�������

//// ��־���
//// __VA_ARGS__ �ɱ����
//#define LOG(FORMAT, ...) printf(FORMAT, __VA_ARGS__);
//
//// ��־�������
//#define LOG_I(FORMAT, ...) printf("INFO:"); printf(FORMAT, __VA_ARGS__);
//#define LOG_E(FORMAT, ...) printf("ERROR:"); printf(FORMAT, __VA_ARGS__);

// ������
#define LOG(LEVEL, FORMAT, ...) printf(LEVEL); printf(FORMAT, __VA_ARGS__);
#define LOG_I(FORMAT, ...) LOG("INFO", FORMAT, __VA_ARGS__);
#define LOG_E(FORMAT, ...) LOG("ERROR", FORMAT, __VA_ARGS__);
#define LOG_W(FORMAT, ...) LOG("WARN", FORMAT, __VA_ARGS__);

//Android
//#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);
//LOGI("%s","fix");
//�滻
//__android_log_print(ANDROID_LOG_INFO, "jason", "%s", "fix");

int main(){

    #include "my.txt"

    printfA();

    int i = 90;
    if(i < MAX){
        printf("�� max С\n");
    }

    jni(read);
    jni(write);

//    LOG("%s%d\n", "��С", 88);
    LOG_I("%s%d\n", "������", 140);
    LOG_E("%s%d\n", "����", 110);



    return 0;
}