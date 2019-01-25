/*外部中断*/

#include <reg51.h>

unsigned int i;
void main()
{
    EA = 1;      //中断总控制位
    EX0 = 1;    //外部中断0 控制位
    IT0 = 1;    //触发方式  1：下降沿触发   0：低电平触发    (通过改变INT0口的状态触发中断)
    while(1);
}

void time() interrupt 0
{
    i++;
    P1 = i;
}