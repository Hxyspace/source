/*归并排序--递归算法*/
#include <stdio.h>
#define MAXSIZE 10

//最终结果存放在list1中
void merging(int *list1,int list1_size,int *list2,int list2_size)
{
    int i,j,k;
    int temp[MAXSIZE];

    i = j = k = 0;

    while(i < list1_size && j < list2_size)
    {
        if(list1[i] < list2[j])
            temp[k++] = list1[i++];
        else
            temp[k++] = list2[j++];
    }

    while(i < list1_size)
        temp[k++] = list1[i++];

    while(j < list2_size)
        temp[k++] = list2[j++];
    
    for(int m = 0;m < (list1_size + list2_size);m++)
        list1[m] = temp[m];
}

void merge(int k[], int n)
{
    if (n > 1)
    {
        int *list1 = k;
        int list1_size = n / 2;
        int *list2 = k + n / 2;
        int list2_size = n - list1_size;

        merge(list1, list1_size);     //递归拆分
        merge(list2, list2_size);
        merging(list1, list1_size, list2, list2_size);  //合并
    }
}

int main()
{
    int k[10] = {2, 3, 7, 9, 4, 1, 5, 0, 6, 8};
    merge(k, 10);
    for (int i = 0; i < 10; i++)
        printf("%2d", k[i]);
    putchar('\n');

    return 0;
}