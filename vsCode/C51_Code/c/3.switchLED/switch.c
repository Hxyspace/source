#include <reg52.h>

sbit K1 = P3 ^ 1;    //定义开关位

void main()
{
    while (1)
    {
        if (K1 == 0)
            P2 = 0x00;
        else
            P2 = 0xff;
    }

}