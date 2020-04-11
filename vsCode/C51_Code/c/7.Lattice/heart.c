#include<REG52.H>
#include<intrins.h>
//点阵显示爱心
typedef unsigned char uchar;

sbit SRCLK=P3^6;
sbit rCLK=P3^5;
sbit SER=P3^4;

void Hc595SendByte(uchar dat)    //595三态八位I/O口扩展芯片  设置数据
{
	uchar a;
	SRCLK=0;      //输入控制开关
	rCLK=0;       //输出控制开关
	for(a=0;a<8;a++)
	{
		SER=dat>>7;     //数据输入端口
		dat<<=1;

		SRCLK=1;
		_nop_();     //延时，等待数据输入完成
		_nop_();
		SRCLK=0;
	}

	rCLK=1;
	_nop_();
	_nop_();
	rCLK=0;
}
void delay(uchar i)
{
    while(i--);
}
void main()
{
    uchar code L[8] = {0x70,0xF8,0xFC,0x7E,0x7E,0xFC,0xF8,0x70};
    uchar i,b = 0x80;
    while(1)
    {
        P0=0x7f;
        for(i=0;i<8;i++)
        {
            P0 = ~b;
            b >>= 1;
            Hc595SendByte(L[i]);
            delay(100);
            Hc595SendByte(0x00);
        }
        b = 0x80;
    }
}