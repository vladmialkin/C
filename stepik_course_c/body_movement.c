/*Программа высчитывает максимальную высоту тела, брошенного под углом к горизонту.

Вычисление происходит по формуле:
h = v0 * v0 * sin(a) * sin(a) / (2 * g)
v0 - начальная скорость тела, м/с
a - угол к горизонту в градусах, под которым бросили тело
g - ускорение свободного падения
h - максимальная высота подъема тела

16.06.2025
Автор: Мялькин В.В.*/
#include <stdio.h>
#include <math.h>

int main()
{
    double  a, v0, g = 9.81, h;

    printf("Введите угол к горизонту в градусах.\n");    
    scanf("%lf", &a);

    printf("Введите начальную скорость тела в м/с.\n");
    scanf("%lf", &v0);

    //sin вычисляется в радиан, даны градусы -> перевести градусы в радианы: rad = degree * (M_PI / 180.0)
    //M_PI - число PI

    double arad = a * (M_PI / 180.0);
    h = (v0 * v0 * sin(arad) * sin(arad) / (2 * g));
    
    printf("Максимальная высота подъема %lf м.\n", h);

    return 0;
}
