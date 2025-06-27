/* Программа находит координаты центра прямоугольника с параллельными осями X и Y,
координаты заданы верхней левой и правой нижней точками. Гарантируется, что точка центра будет в целых координатах.
16.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>

void center(int xlt, int ylt, int xrb, int yrb, int *pxc, int *pyc);

int main()
{
    int xlt, ylt, xrb, yrb, pxc, pyc;

    printf("Координаты верхней левой точки: \n");
    scanf("%d%d", &xlt, &ylt);
    printf("Координаты правой нижней точки: \n");
    scanf("%d%d", &xrb, &yrb);
    
    center(xlt, ylt, xrb, yrb, &pxc, &pyc);
    return 0;
}

void center(int xlt, int ylt, int xrb, int yrb, int *pxc, int *pyc)
{
    *pxc = (xlt + xrb) / 2;
    *pyc = (ylt + yrb) / 2;
    printf("%d %d", *pxc, *pyc);  
}
