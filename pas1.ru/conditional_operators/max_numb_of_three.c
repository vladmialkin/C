#include <stdio.h>

/*Определить какое из трех введенных пользователем чисел максимальное и вывести его на экран.*/

int main(){
	int a, b, c, max;
	printf("Введите 3 числа:\n");
	scanf("%d %d %d", &a, &b, &c);
	if ((a > b) && (a > c))
		max = a;
	else if ((b > a) && (b > c))
		max = b;
	else
		max = c;
	printf("Максимальное число: - %d \n", max);
}
