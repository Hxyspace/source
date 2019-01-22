#include <reg52.h>

typedef unsigned int uint;
sbit LED = P1^0;

void main()
{
    uint i = 0;
    TMOD = 0x01;
    TH0 = (65535 - 1000)/256;
    TL0 = (65535 - 1000)%256;
    TR0 = 1;
    TF0 = 0;

    while(1)
    {
        if(TF0 == 1)
        {
            TF0 = 0;
            TH0 = (65535 - 1000)/256;
            TL0 = (65535 - 1000)%256;
            i++;
        }
        if(i == 1000)
        {
            i = 0;
            LED = ~LED;
        }
    }
}