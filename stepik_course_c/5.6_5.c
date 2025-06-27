/* Программа поворачивает прямоугольник на 90 градусов вокруг его центра.
Прямоугольник со сторонами, параллельными осям, задан координатами точек - верхней левой и правой нижней.
Гарантируется, что тесты оставляют прямоугольник после поворота в целых координатах.
16.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>

void rotateC(int *x1, int *y1, int *x2, int *y2);

int main()
{
    int xlt, ylt, xrb, yrb;
    
    printf("Координаты точек: x1 y1 x2 y1: \n");
    scanf("%d %d %d %d", &xlt, &ylt, &xrb, &yrb);
    
    rotateC(&xlt, &ylt, &xrb, &yrb);
    printf("%d %d %d %d\n", xlt, ylt, xrb, yrb);
    return 0;
}

void rotateC(int *x1, int *y1, int *x2, int *y2)
{
    int tmp;

    tmp = *x1;
    *x1 = *y2;
    *y2 = tmp;
    
    tmp = *x2;
    *x2 = *y1;
    *y1 = tmp;
}
