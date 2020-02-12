#include<REG52.H>        //导入c51头文件

sbit LED1 = P2^0;        //sbit 为C51单片机代码的关键字  这是C标准库没有的

void main()
{
    LED1 = 0;
}