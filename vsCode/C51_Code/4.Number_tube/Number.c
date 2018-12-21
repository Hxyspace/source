/*点亮单个数码管*/
#include<reg52.h>

sbit Key1 = P2^2;
sbit Key2 = P2^3;
sbit Key3 = P2^4;

void delay()    //延时
{
    unsigned char i = -1,j = -1;
    while(i--)
    while(j--);
}

void main()
{
    unsigned char Key = 3,i = 0;    //Key 表示八位数码管中那个亮
    unsigned char code a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};     //显示0~9的编码
                             //数组前面加上 code 关键字，把数组存放在只读存储器中  节约ROM的空间
    Key1 = Key%2;
    Key2 = (Key/2)%2;
    Key3 = (Key/4)%2;
    while(1)
    {
        P0 = a[i++];
        delay();
        if(i == 10)
        i = 0;
    }
}