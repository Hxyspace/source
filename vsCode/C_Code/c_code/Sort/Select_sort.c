/*选择排序*/
#include<stdio.h>

void select(int k[],int N)
{
    int i,j,min,temp;
    for(i = 0;i < N-1;i++)
    {
        min = i;
        for(j = i+1;j < N;j++)
        {
            if(k[j] < k[min])
                min = j;
        }
        if(min != i)
        {
            temp = k[min];
            k[min] = k[i];
            k[i] = temp;
        }
    }
}

int main()
{
    int k[10] = {2,3,7,9,4,1,5,0,6,8};
    select(k,10);
    for(int i = 0;i < 10;i++)
    printf("%2d",k[i]);
    putchar('\n');

    return 0;
}