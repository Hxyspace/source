/* EEPROM测试代码 */

/* 接法：EEPROM的SDA和SCL分别接P3.4和P3.3，P1口接八位LED */

#include<reg51.h>
#include<intrins.h>            //_nop_()函数头文件

#define OP_READ 0xa1           //器件地址以及读取操作，0xa1 即为 1010 0001B
#define OP_WRITE 0xa0           //器件地址以及写入操作，0xa1即为 1010 0000B

sbit SDA = P3^4;                //串行数据总线SDA
sbit SCL = P3^3;                //串行数据总线SCL

void delay1ms()                     //延时1毫秒
{
    unsigned char i,j;
    for( i = 0; i < 10; i++)
        for( j = 0; j < 33;j++);
}

void delay(unsigned char n)         //延迟n毫秒
{
    while(n--)
    delay1ms();
}

/* 从AT24Cxx移入数据到MCU */
unsigned char ReadData()
{
    unsigned char i, x;

    for(i = 0; i < 8 ; i++)
    {
        SCL = 1;
        x <<= 1;                        //将x中各二进制位向左移一位
        x |= (unsigned char)SDA;        //将SDA上的数据通过 位或 存入x
        SCL = 0;                        //在SCL下降沿改变数据
    }

    return x;
}


void start()        //开始位
{
    SDA = 1;            //SDA初始化为高电平
    SCL = 1;            //开始数据传送时，要求SCL为高电平
    _nop_();
    _nop_();            //等待4个机器周期
    _nop_();
    _nop_();
    SDA = 0;            //SDA的下降沿被认为是开始信号
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    SCL = 0;            //SCL为低电平时，SDA上数据才允许变化（即允许以后的数据传递）
}

void stop()     //停止位
{
    SDA = 0;
    SCL = 1;        //结束数据传送时，要求SCL为高电平
    _nop_();
    _nop_();
    _nop_();
    _nop_();

    SDA = 1;        //SDA的上升沿被认为是结束信号

    _nop_();
    _nop_();
    _nop_();
    _nop_();

    SDA = 0;
    SCL = 0;
}

/* 在调用此数据写入函数前需先调用start()函数，所以SCL = 0 */
bit WriteCurrent(unsigned char y)
{
    unsigned char i;
    bit ack_bit;                //储存应答位
    for(i = 0; i < 8 ; i++)     //循环移入八个位
    {
        SDA = (bit)(y & 0x80);      //通过“位与”将最高位数据送到SDA

        _nop_();

        SCL = 1;                    //在SCL的上升沿将数据写入AT24Cxx
        
        _nop_();
        _nop_();

        SCL = 0;                //将SCL重置为低电平
        y <<= 1;
    }

    SDA = 1;            //发送设备应在时钟脉冲的高电平期间（SCL = 1）释放
                        //以让SDA线转由接收设备（AT24Cxx）控制
    _nop_();
    _nop_();
    SCL = 1;
    _nop_();
    _nop_();
    _nop_();
    _nop_();

    ack_bit = SDA;          //接受设备向SDA送低电平，表示已经接收到一个字节
                            //若送高电平，表示没有接收到，传送异常
    SCL = 0;                //SCL为低电平时，SDA上数据才允许变化，即以后的数据传输
    return ack_bit;
}

void WriteSet(unsigned char add,unsigned char dat)
{
    start();                        //开始数据传递
    WriteCurrent(OP_WRITE);         //选择要操作的AT24Cxx芯片，并告知要对其写入数据
    WriteCurrent(add);              //写入指定地址
    WriteCurrent(dat);              //向当前地址（上面指定的地址）写入数据
    stop();                         //停止数据传输
    delay(4);                       //一个字节的写入周期为1ms，最好延时1ms以上
}

/* 从AT24Cxx中的当前地址读取数据   出口参数： x （储存读出的数据） */
unsigned char ReadCurrent()
{
    unsigned char x;
    start();
    WriteCurrent(OP_READ);
    x = ReadData();             //将读取数据存入x

    stop();

    return x;
}

unsigned char ReadSet(unsigned char set_addr)       //在指定地址读取
{
    start();
    WriteCurrent(OP_WRITE);         //选择要操作的芯片，并告知气写入
    WriteCurrent(set_addr);         //写入指定地址
    return (ReadCurrent());         //从指定地址读出数据并返回
}

void main()
{
    SDA = 1;            //SDA = 1,SCL = 1,使主从设备处于空闲状态
    SCL = 1;
    WriteSet(0x36,0x0f);        //在指定地址“0x36”中写入数据0x0f
    P1 = ReadSet(0x36);         //从指定地址“0x36”中读取数据并送入P1口显示
}