/*让8个数码管显示1~8*/
#include<reg52.h>

sbit Key1 = P2^2;
sbit Key2 = P2^3;
sbit Key3 = P2^4;

void delay()    //延时   实现动态显示
{
    unsigned char i = -1;
    while(i--);
}

void light(char key)   //指定哪个灯亮
{
    Key1 = key%2;
    Key2 = (key/2)%2;
    Key3 = (key/4)%2;
}

void main()
{
    unsigned char Key = 7,i = 1;    //Key 表示八位数码管中那个亮
    unsigned char code a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};     //显示0~9的编码
                             //数组前面加上 code 关键字，把数组存放在只读存储器中  节约ROM的空间
    while(1)
    {
        light(Key--);
        P0 = a[i++];
        delay();
        if(i == 9)
        {
            i = 1;
            Key = 7;
        }
    }
}