/* Программа переводит градусы Цельсия в градусы Фаренгейта.
Формула:
F = C * 9/5 + 32
F - фаренгейт
C - цельсия
16.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>


float to_fahr(int cel)
{
    float res;
    res = (cel * 1.8) + 32;
    return res;
}

int main()
{
    int cel;
    float f;
    
    printf("Введите градусы Цельсия: \n");
    scanf("%d", &cel);

    f = to_fahr(cel);

    printf("%d Цельсия = %.2f Фаренгейта.\n", cel, f);
}
