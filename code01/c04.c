//
// Created by Major on 2018/12/22 16:02.
//

// ָ�������
// ָ�������һ�����������ʱ��������

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void method(){

    // �������ڴ���������������
    int ids[] = {78, 90, 23, 65, 19};

    printf("%#x\n", ids);
    printf("%#x\n", &ids);
    printf("%#x\n", &ids[0]);

    int *p = ids;
    printf("%d\n", *p);

    // ָ��ļӷ�����ǰ�ƶ� sizeof���������ͣ� ���ֽ�
    p++;
    printf("%d\n", *p);
}

void method1(){
    int uids[5];
    // ͨ��ָ�븳ֵ
    int *p = uids;
    /*int i = 0;
    for(; i < 5; i++){
        uids[i] = i;
    }*/

    int i = 0;
    for(; p < uids + 5; p++){
        *p = i;
//        i++;
        i+=2;
    }

    int j = 0;
    for(; j < 5; j++){
        printf(" ��%d ��Ӧ��ֵΪ %d\n", j, uids[j]);
    }
}

/*
 c �����ڴ����
 1. ջ�� stack
    windows ��ջ�ڴ���� 2M
    ջ�ڴ����Զ����䣬�ͷ�
 2. ���� heap
    �ֶ����䣬�ֶ��ͷţ�����ռ�ò���ϵͳ 80% ���ڴ�
 3. ȫ������̬��
 4. �ַ�������
 5. ���������
 */
void method2(){
    // 40M
    int a[1024 * 1024 * 10]; // �ᵼ�� stack overflow

}

// ���ڴ� ��̬�ڴ����
void method3(){

    // malloc ��������ֽ�
    // ���� 40M ���ڴ�
    int *p = malloc(1024 * 1024 * 10 * sizeof(int));
    // malloc ���ص�Ϊ void *����ʾΪ�������͵�ָ�롣
    float *p1 = malloc(1024 * 1024 * 10 * sizeof(int));

    free(p); // �ͷ��ڴ�
    free(p1);


    getchar();
}

void method4(){
   // ����һ�����飬��ָ̬�������С
   // ��̬�ڴ���䴴�����飬����Ĵ�С�ǹ̶���
//   int a[10];

    int len;
    printf("��������ĳ��ȣ�");
    scanf("%d", &len);

    // �����ڴ�
    int *p = malloc(len * sizeof(int));
    // ��ֵ
    int i = 0;
    for (; i < len; i++) {
        p[i] = rand() % 100; // û�и����ӵ��������ÿ�����ɵ�����ͬ��
        printf("%d, %#x\n", p[i], &p[i]);
    }

    // �ͷ��ڴ�
    free(p);
}

/*
  realloc ���·����ڴ�
  1. ��С
  2. ���� �������ģ�
    �����ǰ�ڴ�����㹻����Ҫ���ڴ�ռ䣬ֱ����չ����ڴ�ռ䣬 realloc ����ԭ����ָ��
    �����ǰ�ڴ��û���㹻���ڴ�ռ䣬ʹ�ö��е�һ������Ҫ����ڴ�飬����ǰ���ݸ��Ƶ��µ��ڴ�飬�ͷ�֮ǰ���ڴ�飬 realloc �����µ�ָ��
    ����ʧ�ܣ����� NULL��ԭ����ָ����Ȼ��Ч
 */

void method5(){
    int len;
    printf("��һ����������ĳ���: ");
    scanf("%d", &len);

    int *p = malloc(len * sizeof(int));
//    int *p = calloc(len, sizeof(int));

    int i = 0;
    for (; i < len; i++) {
        p[i] = rand() % 100;
        printf("%d, %#x\n", p[i], &p[i]);
    }

    int addLen;
    printf("�����������ӵĳ��ȣ�");
    scanf("%d", &addLen);
    // �����ڴ�ռ�
    int *p2 = realloc(p, sizeof(int) * (len + addLen));

    if (p2 == NULL) {
        printf("�����ڴ����ʧ��");
    }

    // ��ֵ
    i = 0;
    for (; i < len + addLen; i++) {
        p2[i] = rand() % 200;

        printf("%d, %#x\n", p2[i], &p2[i]);
    }

    // p ���Զ��ͷ�
//    if (p != NULL) {
//        free(p);
//        p = NULL;
//    }

    if(p2 != NULL){
        free(p2);
        p2 = NULL;
    }
}


/*
 �ڴ����ע������
  1. ���ܶ���ͷ�
  2. �ͷ�����ָ���� NULL
  3. �ڴ�й©��p ���¸�ֵ֮���� free����û�������ͷ��ڴ棩
 */
void method6(){

    int len;
    printf("��������ĳ��ȣ�");
    scanf("%d", &len);

    int *p = malloc(len * sizeof(int));
    int i = 0;
    for(; i < len; i++){
        p[i] = rand() * 200;
        printf("%d, %#x\n", p[i], &p[i]);
    }

    if(p != NULL){
        free(p);
        p = NULL;
    }
}

void method7(){
    int *p1 = malloc(1024 * 1024 * 10 * sizeof(int));
    free(p1); // ���û�����У��������ڴ�й©
    printf("%#x\n", p1); // p1 free �󲻻�Ϊ NULL����Ҫ�ֶ�����
    p1 = NULL;

    p1 = malloc(1024 * 1024 * 10 * sizeof(int) * 2);
    free(p1);
    p1 = NULL;
}


int main(){

//    method();
//    method1();
//    method2();
//    method3();
//    method4();
//    method5();
//    method6();
    method7();


    return 0;
}