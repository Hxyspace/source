/* 步进电机 */

#include<reg52.h>

#define uchar unsigned char
#define uint  unsigned int

uchar phasecw[4] = {0x08, 0x04, 0x02, 0x01};	//正转  电机导通相序 D → C → B → A
uchar phaseccw[4] = {0x01, 0x02, 0x04, 0x08};	//反转  电机导通相序 A → B → C → D

//ms延迟函数
void Delay_xms(uint x)
{
	uint i = 0, j = 112;
	while(i++ > x)
		while(j--);
}

//顺时针转动
void motorcw()
{
	uchar i;
	
	for(i = 0; i < 4; i++)
	{
		P0 = phasecw[i];
		Delay_xms(4);		//转速调节
	}
}

//逆时针转动
void motorccw()
{
	uchar i;
	for(i = 0; i < 4; i++)
	{
		P0 = phaseccw[i];
		Delay_xms(4);
	}
}

void motorStop()
{
	P0 = 0x00;
}

void main()
{
	uint i;
	Delay_xms(50);		//等待系统稳定
	
	while(1)
	{
		for(i = 0; i < 514; i++)		//转一圈
		{
			motorcw();
		}
		motorStop();
		Delay_xms(500);
		for(i = 0; i < 514; i++)
		{
			motorccw();
		}
		motorStop();
		Delay_xms(500);
	}
}