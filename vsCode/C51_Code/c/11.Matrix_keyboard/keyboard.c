/*矩阵键盘*/
#include<reg51.h>

sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;
unsigned char code Tab[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x09};  //数码管0~9编码
unsigned char keyval;    //按键值

void led_delay()   //延时  消除数码管余辉
{
    unsigned int j = 500;
    while(j--);
}

void display()
{
    P2 = 0x01;     //点亮数码管DS6
    P0 = Tab[keyval/10];     //显示十位
    led_delay();
    P2 = 0x02;     //点亮数码管DS7
    P0 = Tab[keyval%10];   //显示个位
    led_delay();

}

void delay20ms()    //延时子程序
{
    unsigned char i = 100,j = 60;
    while(i--)
        while(j--);
}

void main()
{
    EA = 1;
    ET0 = 1;             //定时器T0中断允许
    TMOD = 0x01;                  //使用定时器T0的模式1      （模式1:16位定时器  常用的）
    TH0 = (65535 - 500)/256;      //定时器高八位赋初值
    TL0 = (65535 - 500)%256;      //定时器低八位赋初值
    TR0 = 1;                      //启动定时器T0
    keyval = 0x00;

    while(1)
    {
        display();
    }
}

void keyboard() interrupt 1
{
    TR0 = 0;                    //关闭定时器
    P1 = 0xf0;                  //所有行线置低电平   列线置高电平
    if((P1 & 0xf0) != 0xf0)     //列线中有一位为低电平，则说明有键按下
        delay20ms();            //消抖
    if((P1 & 0xf0) != 0xf0)     //确实有键按下
    {
        P1 = 0xfe;              //第一行置低电平
        if(P14 == 0)
            keyval = 1;
        if(P15 == 0)
            keyval = 2;
        if(P16 == 0)
            keyval = 3;
        if(P17 == 0)
            keyval = 4;
        
        P1 = 0xfd;             //第二行置低电平
        if(P14 == 0)
            keyval = 5;
        if(P15 == 0)
            keyval = 6;
        if(P16 == 0)
            keyval = 7;
        if(P17 == 0)
            keyval = 8;  

        P1 = 0xfb;
        if(P14 == 0)
            keyval = 9;
        if(P15 == 0)
            keyval = 10;
        if(P16 == 0)
            keyval = 11;
        if(P17 == 0)
            keyval = 12;

        P1 = 0xf7;
        if(P14 == 0)
            keyval = 13;
        if(P15 == 0)
            keyval = 14;
        if(P16 == 0)
            keyval = 15;
        if(P17 == 0)
            keyval = 16;
    }
    TR0 = 1;
    TH0 = (65535 - 500)/256;      //定时器高八位赋初值
    TL0 = (65535 - 500)%256;      //定时器低八位赋初值
}