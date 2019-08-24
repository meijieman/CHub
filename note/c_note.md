## C
> 所有的 C 语言程序都需要包含 main() 函数。 代码从 main() 函数开始执行。

* 当前最新的C语言标准为 C11 ，在它之前的C语言标准为 C99。

 gcc 编译器
 
 `$ gcc -v`


 Windows 上安装 GCC，需要安装 MinGW。 www.mingw.org

安装 cygwin 工具链，支持编译 x64 的
安装参考 https://blog.csdn.net/u012778714/article/details/74012013

### 关键字
auto	声明自动变量  
break	跳出当前循环  
case	开关语句分支  
char	声明字符型变量或函数返回值类型  
const	声明只读变量  
continue	结束当前循环，开始下一轮循环  
default	开关语句中的"其它"分支  
do	循环语句的循环体  
double	声明双精度浮点型变量或函数返回值类型  
else	条件语句否定分支（与 if 连用）  
enum	声明枚举类型  
extern	声明变量或函数是在其它文件或本文件的其他位置定义  
float	声明浮点型变量或函数返回值类型  
for	一种循环语句  
goto	无条件跳转语句  
if	条件语句  
int	声明整型变量或函数  
long	声明长整型变量或函数返回值类型  
register	声明寄存器变量  
return	子程序返回语句（可以带参数，也可不带参数）  
short	声明短整型变量或函数  
signed	声明有符号类型变量或函数  
sizeof	计算数据类型或变量长度（即所占字节数）  
static	声明静态变量  
struct	声明结构体类型  
switch	用于开关语句  
typedef	用以给数据类型取别名  
unsigned	声明无符号类型变量或函数  
union	声明共用体类型  
void	声明函数无返回值或无参数，声明无类型指针  
volatile	说明变量在程序执行中可被隐含地改变  
while	循环语句的循环条件

C99 新增关键字
_Bool	_Complex	_Imaginary	inline	restrict

C11 新增关键字
_Alignas	_Alignof	_Atomic	_Generic	_Noreturn   _Static_assert	_Thread_local

### 数据类型
1 基本类型：
它们是算术类型，包括两种类型：整数类型和浮点类型。
2 枚举类型：
它们也是算术类型，被用来定义在程序中只能赋予其一定的离散整数值的变量。
3 void 类型：
类型说明符 void 表明没有可用的值。
4 派生类型：
它们包括：指针类型、数组类型、结构类型、共用体类型和函数类型。

* 数组类型和结构类型统称为聚合类型。函数的类型指的是函数返回值的类型。

#### 整数类型

|类型           |    存储大小 |   值范围|
|---------------|-------------|-------------|
|char           | 1 字节      |	-128 到 127 或 0 到 255|
|unsigned char	| 1 字节	      | 0 到 255|
|signed char	| 1 字节	      | -128 到 127|
|int	        | 2 或 4 字节 | 32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647|
|unsigned int	| 2 或 4 字节 |  到 65,535 或 0 到 4,294,967,295|
|short	        | 2 字节      | 32,768 到 32,767|
|unsigned short	| 2 字节	     | 0 到 65,535|
|long	        | 4 字节      | 	-2,147,483,648 到 2,147,483,647|
|unsigned long	| 4 字节      |  到 4,294,967,295|

#### signed, unsigned
* signed 有符号，可修饰 char, int(int 默认有符号)
* unsigned 无符号，可修饰 char, int, short, long



#### 数组指针和指针数组
`int (*p)[n]`:数组指针:首先p是一个指针,指向一个整型的一维数组.这个一维数组的长度是n. 
//数组指针也称为指向一维数组的指针,也称行指针 
`int*p[n]`: p[n]是一个数组,加上int*表示整型指针数组. 所以p是一个数组. 只存在p[0],p[1]..这样的.


## C语言标准
C89 (C90)
AMD1 (C94, C95)
C99
C11

## 动态分配内存 malloc,calloc,realloc函数之间的区别 
1. malloc:从堆区分配指定字节的内存,分配成功则返回已分配内存的首地址,否则返回NULL. 
void* malloc (size_t size),使用时将返回结果强制转换为分配的类型
memset(p, 0, 10) //把一个int[10]清零

2. calloc: 类似malloc, 默认初始化,适合为数组申请空间,将size设置为数组元素的长度,num设置为数组的长度. 
void* calloc (size_t num, size_t size); //申请num*size个字节长度的连续内存空间

3. realoc: 可以实现内存分配和释放 
   void* realloc (void* ptr, size_t size); 
   ptr必须为需要重新分配的堆空间指针,即由这三个函数分配空间的指针,size为新的内存空间的大小.可以比原来大,小或者不变. 如果malloc()和 calloc() 分配的不够时,可以用realoc()来调整已经分配的内存.

## C字符串和C++字符串
* 在C中，并没有字符串这个数据类型，而是使用字符数组来保存字符串。C字符串实际上就是一个以null('\0')字符结尾的字符数组，null字符表示字符串的结束。需要注意的是：只有以null字符结尾的字符数组才是C字符串，否则只是一般的C字符数组。

* 在C++中则把字符串封装成了一种数据类型string,可以直接声明变量并进行赋值等字符串操作。以下是C字符串和C++中string的区别：


## 参考
* http://www.runoob.com/cprogramming/c-tutorial.html
* http://www.kuqin.com/clib/string/strcpy.html
* https://juejin.im/entry/592e3180a0bb9f00571b09e9














