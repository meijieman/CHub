//
// Created by Major on 2018/12/21 23:58.
//

__declspec(dllexport) void go(){
    // 外挂程序，修改指定内存的值
    int *p = (int*)0x2ff9d8;
    *p = 9999;
}