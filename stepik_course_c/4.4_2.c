/* Программа вычисляет площадь треугольника.
Формула:
S = sqrt(p *(p - a) * (p - b) * (p - c))

p = (a + b + c) / 2

S - площадь треугольника
p - полупериметр, вычисляется по формуле
a, b, c - стороны треугольника

16.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2);

float area(int x1, int y1, int x2, int y2, int x3, int y3);

int main()
{
    int x1, y1, x2, y2, x3, y3;
    float s;
    
    printf("Координаты первой точки:\n");
    scanf("%d%d", &x1, &y1);
    printf("Координаты второй точки:\n");
    scanf("%d%d", &x2, &y2);
    printf("Координаты третьтей точки:\n");
    scanf("%d%d", &x3, &y3);
    
    s = area(x1, y1, x2, y2, x3, y3);
    printf("Площадь треугольника %.3f\n",s);
    return 0;
} 

float dist(int x1, int y1, int x2, int y2)
{
    float res;
    res = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return res;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int a, b, c, p;
    float res;
    a = dist(x1, y1, x2, y2);
    b = dist(x2, y2, x3, y3);
    c = dist(x3, y3, x1, y1);
    p = (a + b + c) / 2;
    res = sqrt(p * (p - a) * (p - b) * (p - c));
    return res;
}
