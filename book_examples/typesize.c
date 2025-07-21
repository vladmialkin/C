/*Выводит размеры типов в текущей системе*/
#include <stdio.h>
int main()
{
	printf("Тип int - %zd байт.\n", sizeof(int));
	printf("Тип char - %zd байт.\n", sizeof(char));
	printf("Тип long - %zd байт.\n", sizeof(long));
	printf("Тип long long - %zd байт.\n", sizeof(long long));
	printf("Тип double - %zd байт.\n", sizeof(double));
	printf("Тип long double - %zd байт.\n", sizeof(long double));
	return 0;
}

