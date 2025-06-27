/* Реализовать функцию вычисления корней квадратного уравнения.
Формула:
d = b * b - 4 * a * c;
d - дискриминант
x1, x2 = (-b +- sqrt(d)) / (2 * a)
17.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <math.h>

void sq(int a, int b, float d, float *x1, float *x2);

float discriminant(int a, int b, int c);

int main()
{
    int a, b, c;
    float d, x1, x2;
    
    printf("Введите a, b, c квадратного уравнения: \n");
    scanf("%d%d%d", &a, &b, &c);
    
    d = discriminant(a, b, c);
    
    if (d >= 0){
        sq(a, b, d, &x1, &x2);
        if (x1 == x2)
            printf("Один корень: %f\n", x1);
        else
            printf("Два корня: %0.2f %0.2f\n", x1, x2);
    }
    else
        printf("Корней нет.\n");
    return 0;
}


float discriminant(int a, int b, int c)
{
    float d;
    d = b * b - 4 * a * c;
    return d;
}

void sq(int a, int b, float d, float *x1, float *x2)
{
    *x1 = (-1 * b + sqrt(d)) / (2 * a);
    *x2 = (-1 * b - sqrt(d)) / (2 * a); 
}
