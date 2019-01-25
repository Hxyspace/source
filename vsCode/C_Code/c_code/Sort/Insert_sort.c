/*直接插入排序*/
#include<stdio.h>

void insert(int k[],int N)
{
    int i,j,temp;
    for(i = 1;i < N;i++)
    {
        if(k[i] < k[i-1])
        {
            temp = k[i];
            for(j = i-1;k[j] > temp && j >= 0;j--)
            {
                k[j+1] = k[j];
            }
            k[j+1] = temp;
        }
    }
}

int main()
{
    int k[10] = {2,3,7,9,4,1,5,0,6,8};
    insert(k,10);
    for(int i;i < 10;i++)
    printf("%2d",k[i]);
    putchar('\n');

    return 0;
}