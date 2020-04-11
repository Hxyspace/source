/*走马灯程序*/
#include<reg52.h>

void delay()    //延时
{
    unsigned char i = -1,j = -1;
    while(i--)
    while(j--);
}

void main()
{
    unsigned char b = 1;
    while(1)
    {
        P2 = ~b;       //取反，0的位数表示灯亮
        b <<= 1;
        if(b == 0)
        b = 1;
        delay();
    }
}