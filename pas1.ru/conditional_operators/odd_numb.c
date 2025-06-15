#include <stdio.h>

/*Из двух чисел с разной четностью вывести на экран нечетное число.*/

int main(){
	int a,b, odd;
	printf("Введите одно четное и одно нечетное число\n");
	scanf("%d %d", &a, &b);
	if (a % 2 != 0)
		odd = a;
	else
		odd = b;
	printf("%d - нечетное число.", odd);
}
