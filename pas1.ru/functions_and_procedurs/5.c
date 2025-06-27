/* Программа вычисляет НОК пар чисел.
Формула:
lcm = a*b / gcd
lcm - НОК
gcd - НОД a и b

gcd вычисляется по алгоритму Евклида - разделить большее число на маньшее 
и получить остаток. Заменить Большее число на маньшее, а меньшее на остаток.
Повторять, пока остаток не станет равен 0. Последний ненулевой остаток - это НОД.
18.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <stdlib.h>

int getGcd(int a, int b);
int getLcm(int a, int b, int gcd);

int main()
{
    int a, b, 
        lcm, // НОК
        gcd; // НОД
    printf("Введите a и b: \n");
    if (scanf("%d%d", &a, &b) != 2){
        printf("Неверный ввод.\n");
        abort();
    }
    
    gcd = getGcd(a, b);
    lcm = getLcm(a, b, gcd);
    printf("НОК %d и %d = %d\n", a, b, lcm);
    return 0;
}

int getGcd(int a, int b)
{   
    int tmp;
    while (a % b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return b; 
}

int getLcm(int a, int b, int gcd)
{
    long int op = a * b;
    return (int)(op / gcd);
}
