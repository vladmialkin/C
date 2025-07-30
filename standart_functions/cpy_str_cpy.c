/* Программа тестирует функции str_cpy и str_ncpy*/
#include <stdio.h>
#include "standart_functions.h"

int main(void)
{
	char *str1 = "test";
	char *str2 = "new";
	char *str3 = "it's ";
	char *str4 = "1234567890zxcvb";
	char buff[1024] = "";
	int n;

	str_cpy(buff, str1);
	puts(buff);
	str_cpy(buff, str2);
	puts(buff);
	str_cpy(buff, str3);
	puts(buff);
        printf("Введите количество элементов, которые нужно скопировать из строки \"%s\"", str4);
	while(scanf("%d", &n) != 1)
		puts("Нужно ввести одно положительное число");
	printf("Копирует %d символов из строки \"%s\"\n", n, str4);
	str_ncpy(buff, str4, n);
	puts(buff);
	puts("Заверешние программы.");
	return 0;
}
