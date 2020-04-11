//蜂鸣器发声
#include<reg52.h>

sbit beep = P1^5;
typedef unsigned char uchar;

void delay(uchar i)
{
    while(i--);
}

void main()
{
    beep = 1;
    while(1)
    {
        beep = ~beep;
        delay(-1);
    }
}