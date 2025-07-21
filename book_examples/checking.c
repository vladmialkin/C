/* Программа проверяте допустимость ввода. Программа взята из книги "Язык программирования на С. Лекции и упражнения. Стивен Прата" на странице 313.
 * 18.07.2025
 * Автор: Мялькин В.В.*/
#include <stdio.h>
#include <stdbool.h>
//проверка, является ли ввод целочисленным
long get_long(void);
//проверка, доступны ли границы диапазона
bool bad_limits(long begin, long end, long low, long high);
//вычисление суммы квадратов целых чисел от а до b
double sum_squares(long a, long b);

int main()
{
	const long MIN = -10000000L;
	const long MAX = +10000000L;
	long start;
	long stop;
	double answer;
	printf("Эта программа вычисляет сумму квадратов целых чисел в заданном диапазоне.\n"
	       "Нижняя граница не должна быть меньше -1000000,\nа верхняя не должна быть больше +10000000.\n"
	       "введите значения пределов (для завершения введите 0 для обоих пределов):\n"
	       "нижний предел: ");
	start = get_long();
	printf("верхний предел: ");
	stop = get_long();
	while( start !=0 || stop != 0)
	{
		if (bad_limits(start, stop, MIN, MAX))
			printf("Повторите попытку.\n");
		else{
			answer = sum_squares(start, stop);
			printf("Сумма квадратов целых чисел от %ld до %ld равна %g\n", start, stop, answer);
		}
		printf("Введите значения пределов (для завершения введи 0 для обоих пределов): \n");
		printf("нижний предел: ");
		start = get_long();
		printf("верхний предел: ");
		stop = get_long();
	}
	printf("Программа завершена.\n");
	return 0;
}

long get_long(void)
{
	long input;
	char ch;
	while(scanf("%ld", &input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch); //отбросить неправильный ввод
		printf(" не является целочисленным.\n Введите целое число, такое как 25, 179, -3: ");
	}
	return input;
}

double sum_squares(long a, long b)
{
	double total = 0;
	long i;
	for(i = a; i <= b; i++)
		total += (double)i * (double)i;
	
	return total;
}

bool bad_limits(long begin, long end, long low, long high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf("%ld меньще чем %ld\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf("Значения должны быть равны %ld или больше.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("Значения должны быть равны %ld или меньше.\n", high);
		not_good = true;
	}
	return not_good;
}

