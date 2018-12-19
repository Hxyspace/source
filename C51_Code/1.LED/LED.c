#include <reg52.h> 
//sbit对位操作的声明，该行表示将P1.0口重新命名为LED1，对p1^0口输出为0就会发光了，操作第二个灯可设变量sbit LED2 = P1^1;
sbit LED1 = P1^0; void main()
{
    //给LED1赋值0，相当于灯亮。
    LED1 = 0;
}