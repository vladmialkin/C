/* Программа проверяет работу функции str_cmp */
#include <stdio.h>
#include "standart_functions.h"

int main(void)
{
	char buff1[128];
	char buff2[128];
	int n;
	puts("Введите строку 1: ");
	fgets(buff1, 128, stdin);
	puts("Введите строку 2: ");
	fgets(buff2, 128, stdin);

	if (str_cmp(buff1, buff2) == 0)
		puts("Строки равны.");
	else
		puts("Строки не равны.");

	puts("Введите число, до какого значения сравнивать строки: ");
	scanf("%d", &n);
	if (str_ncmp(buff1, buff2, n) == 0)
		puts("Строки равны.");
	else
		puts("Строки не равны.");

	puts("Завершение программы.");
	return 0;
}
