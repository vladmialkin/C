/*Реализовать функцию нахождения по заданным длине стороны треугольника и прилежащим углам длин остальных сторон.
Формула:
sin A / BC = sin B  / AC = sin C / AB
sin выражен в радианах, приводим к градусам:
rad = y * PI / 180
rad - радианы
y - угол

17.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <math.h>

void triangle(int a, int b, int c, float ab, float *bc, float *ac);

float radianToGrade(int x);

int main()
{
    int a, b, c; // углы треугольника в градусах
    float ab, bc, ac; // стороны треугольника
    printf("Введите 2 угла треугольника в градусах: \n");
    scanf("%d%d", &a, &b);
    printf("Введите сторону треугольника: \n");
    scanf("%f", &ab);
    
    c = 180 - a - b;
    triangle(a, b, c, ab, &bc, &ac);
    printf("Углы треугольника: %d %d %d\n", a, b, c);
    printf("Стороны треугольника: %0.2f %0.2f %0.2f\n", ab, bc, ac);
    return 0;  
}

void triangle(int a, int b, int c, float ab, float *bc, float *ac)
{
    float radA, radB, radC;
    radA = radianToGrade(a);
    radB = radianToGrade(b);
    radC = radianToGrade(c);
    
    *bc = (sin(radA) * ab) / sin(radC);
    *ac = (sin(radB) * ab) / sin(radC);
}

float radianToGrade(int x)
{
    float res;
    res = x * M_PI / 180.0;
    return res;
}
