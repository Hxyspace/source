/*冒泡排序*/
#include<stdio.h>

void bubble(int k[],int N)
{
    int i,j,temp;
    for(i = 0;i < N ;i++)
        for(j = N-1;j > i;j--)
        {
            if(k[j] < k[j-1])
            {
                temp = k[j];
                k[j] = k[j-1];
                k[j-1] = temp;
            }
        }
}

int main()
{
    int k[10] = {2,3,7,9,4,1,5,0,6,8};
    bubble(k,10);
    for(int i = 0;i < 10;i++)
    printf("%2d",k[i]);
    putchar('\n');

    return 0;
}