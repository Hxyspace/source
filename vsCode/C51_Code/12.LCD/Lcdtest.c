/*液晶显示屏*/

#include <reg51.h>
#include <intrins.h>         //包含_nop_()函数的头文件

typedef unsigned char uchar;
typedef unsigned int uint;

sbit RS = P2^6;              //寄存器选择位
sbit RW = P2^5;             //读写选择位
sbit E  = P2^7;              //使能信号位
sbit BF = P0^7;             //忙碌标志位

void delay1ms()              //延时1ms    (3j+2) * i = (3 * 33 + 2) * 10 = 1010(微秒)   约为1毫秒
{
    uchar i,j;
    for(i=0;i<10;i++)
        for(j=0;j<33;j++);
}

void delay(uchar n)         //延迟n毫秒
{
    while(n--)
        delay1ms();
}

bit BusyTest()            //是否忙碌
{
    bit result;

    RS = 0;             //RS为低电平 RW为高电平  可以读状态
    RW = 1;
    E  = 1;             //E 为 1 ，允许读写
    _nop_();
    _nop_();
    _nop_();
    _nop_();            //空闲四个机器周期  给硬件反应时间

    result = BF;    //忙碌标志

    E = 0;
    return result;
}

void WriteInstruction(uchar dictate)        //写入指令或写入显示地址
{
    while(BusyTest() == 1);   //忙碌则等待

    RS = 0;                     //RS、RW都为低电平，允许写指令
    RW = 0;
    E  = 0;

    _nop_();
    _nop_();            //空两个周期时间

    P0 = dictate;       //将数据送入P0口  即写入指令或地址

    _nop_();
    _nop_();
    _nop_();
    _nop_();

    E  = 1;             //形成高脉冲

    _nop_();
    _nop_();
    _nop_();
    _nop_();

    E = 0;

}

void WriteAddress(uchar x)      //指定字符的实际地址
{
    WriteInstruction(x + 0x80);         //显示位置的确定方法为“ 80H + 地址 ”
}

void WriteData(uchar y)         //将数据写入液晶模块
{
    while(BusyTest() == 1);

    RS = 1;                 //RS高  RW低   可以写入数据
    RW = 0;
    E  = 0;

    P0 = y;      //写入数据

    _nop_();
    _nop_();
    _nop_();
    _nop_();

    E = 1;          //高脉冲

    _nop_();
    _nop_();
    _nop_();
    _nop_();

    E = 0;
}

void LcdInit()              //对LCD显示模式进行初始化设置
{
    delay(15);                  //首次写入指令需要给LCD一段时间
    WriteInstruction(0x38);     //显示模式设置 ： 16 x 2 显示 ， 5 x 7点阵
    delay(5);
    WriteInstruction(0x38);
    delay(5);
    WriteInstruction(0x38);
    delay(5);
    WriteInstruction(0x0f);         //显示模式： 显示开，有光标，光标闪烁
    delay(5);
    WriteInstruction(0x06);         //光标右移，字符不变
    delay(5);
    WriteInstruction(0x01);         //清屏指令，将以前显示的内容清除
    delay(5);

}

void main()
{
    LcdInit();      //初始化LCD
    WriteAddress(0x70);         //显示地址  指定为第一列第8行
    WriteData('A');         //显示字符 A   （字符的字形点阵读出和显示由液晶模块自动完成）
}