/*快速排序*/
#include<stdio.h>

void swap(int k[],int low,int high)
{
    int temp;
    temp = k[high];
    k[high] = k[low];
    k[low] = temp;
}

int partition(int k[],int low,int high)
{
    int point;

    point = k[low];

    while(low < high)
    {
        while(low < high && k[high] >= point)
        {
            high--;
        }

        swap(k,low,high);

        while(low < high && k[low] <= point)
        {
            low++;
        }

        swap(k,low,high);
    }

    return low;
}

void QuickSort(int k[],int low,int high)
{
    int point;

    if(low < high)
    {
        point = partition(k,low,high);

        QuickSort(k,low,point-1);

        QuickSort(k,point+1,high);
    }
}

void Quick(int k[],int N)
{
    QuickSort(k, 0, N-1);
}

int main()
{
    int k[10] = {2,3,7,9,4,1,5,0,6,8};
    Quick(k,10);
    for(int i = 0;i < 10;i++)
    printf("%2d",k[i]);
    putchar('\n');
    return 0;;
}