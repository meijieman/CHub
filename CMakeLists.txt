cmake_minimum_required(VERSION 3.13)
project(CHub)

#set(CMAKE_C_STANDARD 99)
#set(BUILD_USE_64BITS on)

add_subdirectory(code02)

add_executable(chub main.c)

add_executable(chub_01 code01/c01.c)
add_executable(chub_02 code01/c02.c)
#add_executable(chub_cheater cheater.c)
add_executable(chub_03 code01/c03.c)
add_executable(chub_04 code01/c04.c)
add_executable(chub_05 code01/c05.c)
add_executable(chub_06 code01/c06.c)
add_executable(chub_07 code01/c07.c)
add_executable(chub_08 code01/c08.c)
add_executable(chub_09 code01/c09.c)
add_executable(chub_10 code01/c10.c)
add_executable(chub_11 code01/c11.c)
add_executable(chub_12 code01/c12.c)

add_executable(chub_jni02 jni/jni02.c)
add_library(jnitest SHARED jni/jni01.c jni/com_company_JniTest.h)

add_executable(chub_WebClnt http/WebClnt.c)
add_executable(chub_WebSrv http/WebSrv.c)
