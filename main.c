#include <stdio.h>

int add(int a, int b){

    return a + b;
}

void arr(){
    printf("---------����-----------\n");
    int ar[10];
    for (int k = 0; k < 10; k++) {
        printf("%d ", ar[k]);
    }
    printf("\n");
    int *ap = ar;
    int *a1 = &ar[0];
    printf("ap = %d, a1 = %d\n", ap, a1);

    int ap0 = ap[2];
    int ar0 = ar[2];
    printf("ap0 = %d\n", ap0);
    printf("ar0 = %d\n", ar0);

    *ar = 11; // �Ե�һ��Ԫ�ظ�ֵ
    *(ar + 1) = 12; // �Եڶ���Ԫ�ظ�ֵ
    printf("ar[0]=%d, ar[1]=%d\n", ar[0], ar[1]);

    int arr1[10] = {1};
    int arr2[10] = {1, 2};
    for (int j = 0; j < 10; ++j) {
        printf("%d ", arr1[j]);
    }
    printf("\n");

    for (int j = 0; j < 10; ++j) {
        printf("%d ", arr2[j]);
    }
    printf("\n");

    int aa[3][4]; // ��ά����
    int (*p)[4]; // ����һ������ָ��,����ֵҲ��һ����СΪ4������
    p = aa;
    p++; // p ָ�� a[1][]
    aa[1][0] = 2;
    printf("p[0] = %d", *p[0]); // *p��ȡֵ,��Ϊ����ֵ��һ������,���Կ���ֱ��[0]�õ���һ��Ԫ��
}


void point(){
    printf("-------------\n");
    char a[5] = "12345", *b;
    b = a;
    printf("b ��ֵ��%c\n", *b);
    b +=2;
    printf("b ��ֵ��ɣ�%c\n", *b);
    printf("(b + 1) ��ֵ��%c\n", *(b + 1));

    char **aa = &a;
    char **bb = &b;
    //**bb,��ȡ*(*b)�д洢��ֵ,���Ǵ洢b�ĵ�ֵַ(��*b),Ȼ����һ��*��ʾȡ��b��ֵ
    printf("bb = %p, bb ����ָ���ֵ��%c, aa = %c\n", *bb, **bb, *aa);
}

// ����ָ��
//void (*p)(char const *str):��������Ϊvoid,����Ϊchar const *str,������Ϊp,�������βκ�����,����һ������ָ��,���Դ���һ����������
void sayHi(void (*p)(char const *str)) {
    p("hi2");
}

void print(char const *str) {
    printf("%s\n", str);
}

int main() {
    printf("Hello, World!\n");


    int i = 10;

    printf("%d\n", i);
    printf("int ��С %d\n", sizeof(int));

    printf("%d\n", add(2, 5));

//    arr();
//    point();

    sayHi(print); //����ֱ�Ӵ���print����

    return 0;
}