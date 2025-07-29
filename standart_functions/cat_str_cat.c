/* Программа тестирует функцию str_cat*/
#include <stdio.h>
#include "standart_functions.h"

int main(void)
{
	char *str1 = "Строка 1";
	char *str2 = "Строка 2";
	int res_len;
	char buff1[128];
	char buff2[128];
	puts("Введи строку 1: ");
	fgets(buff1, 128, stdin);
	puts("Введи строку 2: ");
	fgets(buff2, 128, stdin);
	printf("str_cat: ");
	puts(str_cat(buff1, buff2, &res_len));
	printf("str_cat2: ");
	puts(str_cat2(buff1, buff2));
	puts("Другой пример: ");
	puts(str_cat(str1, str2, &res_len));
	puts("Готово");
	return 0;
}
