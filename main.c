#include <stdio.h>

int add(int a, int b){

    return a + b;
}

void arr(){
    printf("---------数组-----------\n");
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

    *ar = 11; // 对第一个元素赋值
    *(ar + 1) = 12; // 对第二个元素赋值
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

    int aa[3][4]; // 二维数组
    int (*p)[4]; // 定义一个数组指针,他的值也是一个大小为4的数组
    p = aa;
    p++; // p 指向 a[1][]
    aa[1][0] = 2;
    printf("p[0] = %d", *p[0]); // *p是取值,因为他的值是一个数组,所以可以直接[0]拿到第一个元素
}


void point(){
    printf("-------------\n");
    char a[5] = "12345", *b;
    b = a;
    printf("b 的值：%c\n", *b);
    b +=2;
    printf("b 的值变成：%c\n", *b);
    printf("(b + 1) 的值：%c\n", *(b + 1));

    char **aa = &a;
    char **bb = &b;
    //**bb,先取*(*b)中存储的值,他是存储b的地址值(即*b),然后再一个*表示取出b的值
    printf("bb = %p, bb 最终指向的值：%c, aa = %c\n", *bb, **bb, *aa);
}

// 函数指针
//void (*p)(char const *str):返回类型为void,参数为char const *str,函数名为p,这里是形参函数名,他是一个函数指针,可以传入一个函数进来
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
    printf("int 大小 %d\n", sizeof(int));

    printf("%d\n", add(2, 5));

//    arr();
//    point();

    sayHi(print); //这里直接传入print函数

    return 0;
}