//
// Created by Major on 2018/12/21 22:55.
//
#include <stdio.h>
#include <windows.h> //winͷ�ļ�

int main(){
    int time = 600;
    printf("time:%#x\n",&time);
    while(time > 0){
        time--;
        printf("��Ϸʣ��ʱ�� %d \n", time);
        Sleep(1000);
    }
    
    return 0;
}