//
// File: c02.c
// Created by Major on 2019/10/7 19:54.
//

#include <stdio.h>


/* 古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，
 * 假如兔子都不死，问每个月的兔子总数为多少？兔子的规律为数列1,1,2,3,5,8,13,21....
 *
 * https://baike.baidu.com/item/斐波那契数列/99145?fr=aladdin
 */
int f(int count) {
    if (count <= 0) {
        return -1;
    }

    if (count == 1 || count == 2) {
        return 1;
    }

    return f(count - 1) + f(count - 2);
}

void func1() {
    int month = 5;

    int sum = 0;
    int index = 1;

    while (index <= month) {
        sum += f(index);
        index++;
    }

    printf("%d", sum);
}

long func2() {
    long f1 = 1, f2 = 1;

    for (int i = 1; i <= 20; i++) {
        printf("%12ld  %12ld", f1, f2);
        if(i %2 == 0){
            printf("\n");
        }
        f1 = f1 + f2;
        f2 = f1 + f2;
    }
}

int main() {

    // 斐波拉契数列

//    func1();
    func2();

    return 0;
}


