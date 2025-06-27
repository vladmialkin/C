/*Реализовать функцию, возвращающую среднее арифметическое двух аргументов.
17.06.2025
Автор: Мялькин В.В.
*/

#include <stdio.h>

float mean(int a, int b);

int main()
{
    int a, b;
    float res;
    printf("Введите a и b: \n");
    scanf("%d%d", &a, &b);

    res = mean(a, b);
    printf("Среднее арифметическое %d и %d - %.2f\n", a, b, res);
    return 0;
}

float mean(int a, int b)
{
    float res;
    res = (a + b) / 2.0;
    return res;
}
