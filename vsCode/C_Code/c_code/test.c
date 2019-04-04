#include <stdio.h>

int main()
{
    union {
        long b;
        char c[4];
    } s;

    s.b = 0xa0000L;
    s.c[0] += 'A';
    printf("%d\t%c\n", s.c[2], s.c[0]);

    return 0;
}