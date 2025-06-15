#include <stdio.h>

/*Среди трех чисел найти среднее. Если среди чисел есть равные, вывести сообщение "Ошибка".*/

int main(){
	int a,b,c, avg;
	printf("Введите 3 числа:\n");
	scanf("%d %d %d", &a, &b, &c);

	if (
			(a == b) 
			|| (a == c)
			|| (b == c)
			|| ((a == b) && (b == c))
			){
		printf("Ошибка\n");
		return 0;
	}
	else if (
			((a > b) && (a < c)) 
			|| ((a < b) && (a > c))
			)
		avg = a;
	else if (
			((b > a) && (b < c))
			|| (b < a) && (b > c)
			)
		avg = b;
	else
		avg = c;
	printf("Среднее число -%d\n", avg);
}
