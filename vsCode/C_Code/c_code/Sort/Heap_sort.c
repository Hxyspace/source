/*堆排序*/

#include<stdio.h>

void swap(int k[],int i,int j)    //交换
{
    int temp;
    temp = k[i];
    k[i] = k[j];
    k[j] = temp;
}

void HeapAdjust(int k[],int s,int n)     //生成大堆根
{
    int i,temp;

    temp = k[s];

    for(i = 2*s; i <= n;i *= 2)
    {
        if(i < n && k[i] < k[i+1])
            i++;

        if(temp >= k[i])
            break;
        
        k[s] = k[i];
        s = i;

    }

    k[s] = temp;
}

void heap(int k[],int N)
{
    int i;
    for(i = N/2;i > 0;i--)     //从下往上生成大堆根
    {
        HeapAdjust(k, i, N);
    }

    for(i = N;i > 1;i--)
    {
        swap(k, 1, i);         //将根和最后一个交换
        HeapAdjust(k, 1, i-1);   //将前面未排序的部分生成大堆根
    }
}

int main()
{
    int k[10] = {-1,2,3,7,8,4,1,5,0,6};
    heap(k,9);
    for(int i = 1;i < 10;i++)
    printf("%2d",k[i]);
    putchar('\n');

    return 0;
}