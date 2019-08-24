//
// Created by Major on 2018/12/23 19:59.
//

// 如果没有定义 LEARNC_A_H， 定义 LEARNC_A_H
//#ifndef LEARNC_A_H
//#define LEARNC_A_H
//
//#include "b.h"
//
//void printfA();
//
//#endif //LEARNC_A_H


// 新版本可以如下定义，表示该头文件只被包含一次，让编译器自动处理好循环引用的问题
#pragma  once
#include "b.h"

void printA();
