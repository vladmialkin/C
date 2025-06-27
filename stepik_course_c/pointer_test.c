#include <stdio.h>

int main()
{
    int x = 3;
    int * px;
    int * px1;
    int ** pxx;
    int *** pxxx;
    int **** pxxxx;
    px = &x;
    px1 = &x;
    pxx = &px;
    pxxx = &pxx;
    pxxxx = &pxxx;
    printf("%d - %p\n", *px, px);
    printf("%d - %p - %p\n", **pxx, pxx, *pxx);
    printf("%d - %p - %p\n", ***pxxx, pxxx, *pxxx);
    printf("%d - %p - %p\n", ****pxxxx, pxxxx, *pxxxx);
    return 0;
}
