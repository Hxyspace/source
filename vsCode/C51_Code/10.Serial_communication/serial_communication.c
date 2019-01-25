/*串行通信*/
#include<reg51.h>

unsigned int i;

void main()
{
    TMOD = 0x20;   //定时器工作方式     TMOD:定时器工作方式选择寄存器
    SCON = 0x50;   //串口工作方式      SCON:串口工作方式选择寄存器
    PCON = 0x00;   //波特率不倍增   0x80为波特率倍增    PCON:89C51电源控制寄存器
    TL1 = 0xFD;    //设定定时初值
    TH1 = 0xFD;    //设定定时器重装值
    TR1 = 1;       //启动定时器T1
    EA = 1;
    ES = 1;      //串口中断
    while(1);
}

void serial() interrupt 4
{
    i = SBUF;
    P1 = i;
    RI = 0;     //中断标志位  需手动清零
}