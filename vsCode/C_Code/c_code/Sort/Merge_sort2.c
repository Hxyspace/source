/*归并排序--非递归*/
#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10

void merge(int k[], int n)
{
    int i, left_min, left_max, right_min, right_max;
    int *temp = (int *)malloc(n * sizeof(int));

    for (i = 1; i < n; i++)
    {
        for (left_min = 0; left_min < n - i; left_min = right_max)
        {
            right_min = left_max = left_min + i;
            right_max = left_max + i;

            if (right_max > n)
                right_max = n;

            int next = 0;

            while (left_min < left_max && right_min < right_max)
            {
                if (k[left_min] < k[right_min])
                    temp[next++] = k[left_min++];
                else
                    temp[next++] = k[right_min++];
            }

            while (left_min < left_max)
                k[--right_min] = k[--left_max];

            while (next > 0)
                k[--right_min] = temp[--next];
        }
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