#include <stdio.h>

/*Вводятся два числа (большее и меньшее). Определить, кратно ли первое число второму, то есть делится ли первое число нацело на второе. Вывести на экран сообщение об этом, а также остаток от деления, если первое число не кратно второму.*/

int main(){
	int a,b;
	printf("Введите большее и меньшее число:\n");
	scanf("%d %d", &a, &b);

	if (a % b == 0)
		printf("Первое число кратно второму\n");
	else {
		printf("Первое число не кратно второму\n");
		printf("Остаток от деления = %d\n", a % b);
	}	
}
