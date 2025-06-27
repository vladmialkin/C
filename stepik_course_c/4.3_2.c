/* Программа переводит градусы Фаренгейта в градусы Цельсия.
Формула:
F = C * 9/5 + 32
F - фаренгейт
C - цельсия
16.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>


float to_celsius(int fahr)
{
    float res;
    // res = (cel * 1.8) + 32;
    // res - 32 = cel * 1.8;
    // (res - 32) / 1.8 = cel;
    res = (fahr - 32) / 1.8;
    return res;
}

int main()
{
    float cel;
    int f;
    
    printf("Введите градусы Фаренгейта: \n");
    scanf("%d", &f);

    cel = to_celsius(f);

    printf("%d Фаренгейта = %.4f Цельсия.\n", f, cel);
}
