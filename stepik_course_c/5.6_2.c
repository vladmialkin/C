/* Программа зеркально отображает отрезок с концами (x1, y1) и (x2, y2) относительно оси X
16.06.2025
Автор: Мялькин В.В.*/
 
#include <stdio.h>

void mirror_seg(int *px1, int *py1, int *px2, int *py2);

int main()
{
    int x1, y1, x2, y2;

    printf("Введите координаты первой точки: \n");
    scanf("%d%d", &x1, &y1);

    printf("Введите координаты второй точки: \n");
    scanf("%d%d", &x2, &y2);

    mirror_seg(&x1, &y1, &x2, &y2);

    return 0;
}

void mirror_seg(int *px1, int *py1, int *px2, int *py2)
{
    printf("%d %d %d %d\n", *px1, *py1 * -1, *px2, *py2 * -1); 
}
