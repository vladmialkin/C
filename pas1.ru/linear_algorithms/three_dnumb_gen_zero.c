#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Сгенерировать случайное трехзначное число, оканчивающееся на ноль.*/

int main(){
	srand(time(NULL));
	int n = 100 + rand() % 1000;
	printf("Число - %d\n", n - n % 10);
}
