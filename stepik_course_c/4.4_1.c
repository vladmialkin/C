/*Программа вычисляет расстояние между двумя точками.
Формула:
d = sqrt((x2 - x1)**2 + (y2 - y1)**2)
x1, y1 - координаты первой точки
x2, y2 - координаты второй точки
sqrt - корень
**2 - возведение в степень 2

16.06.2025
Автор: Мялькин В.В.
*/
#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2);

int main()
{
    int x1, y1, x2, y2;
    float len;

    printf("Координаты первой точки: \n");
    scanf("%d%d", &x1, &y1);
    printf("Координаты второй точки: \n");
    scanf("%d%d", &x2, &y2);

    len = dist(x1, y1, x2, y2);
    
    printf("Расстояние между точками(%d, %d) и (%d, %d) = %0.2f\n", x1, y1, x2, y2, len);
    return 0;
}

float dist(int x1, int y1, int x2, int y2)
{
    float res;
    res = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return res; 
}

