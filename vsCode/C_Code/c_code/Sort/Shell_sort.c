/*希尔排序*/
#include<stdio.h>

void shell(int k[],int N)
{
    int i,j,temp;
    int gap = N;
    do
    {
        gap = gap/3 + 1;
        for(i = gap;i < N;i++)
        {
            if(k[i] < k[i-gap])
            {
                temp = k[i];
                for(j = i-gap;k[j] > temp;j -= gap)
                {
                    k[j+gap] = k[j];
                }
                k[j+gap] = temp;
            }
        }
    } while (gap > 1);
    
}

int main()
{
    int k[10] = {2,3,7,9,4,1,5,0,6,8};
    shell(k,10);
    for(int i = 0;i < 10;i++)
    printf("%2d",k[i]);
    putchar('\n');
    return 0;;
}