/*定时器*/

#include <reg52.h>

typedef unsigned int uint;
sbit LED = P1^0;

void main()
{
    uint i = 0;
    TMOD = 0x01;    //中断方式
    TH0 = (65535 - 1000)/256;    //T0寄存器高8位
    TL0 = (65535 - 1000)%256;    //低8位
    TR0 = 1;      //定时器T0启动位
    TF0 = 0;     //定时器T0溢出标志位

    while(1)
    {
        if(TF0 == 1)
        {
            TF0 = 0;
            TH0 = (65535 - 1000)/256;
            TL0 = (65535 - 1000)%256;
            i++;
        }
        if(i == 1000)
        {
            i = 0;
            LED = ~LED;
        }
    }
}