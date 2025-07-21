/* Программа с меню. Программа взята из книги "Язык программирования на С. Лекции и упражнения. Стивен Прата" на странице 319.
 * 18.07.2025
 * Автор: Мялькин В.В.*/
#include <stdio.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main()
{
	int choice;
	void count();
	while( (choice = get_choice()) != 'q')
	{
		switch(choice)
		{
			case 'c': printf("Покупайте дешево, продавайте дорого.\n");
				  break;
			case 'z': putchar('\a');
				  break;
			case 'p': count();
				  break;
			case 'e': break;
			default: printf("Ошибка!\n");
				 break;
		}
	}
	printf("Программа завершена.\n");
	return 0;
}

void count(void)
{
	int n, i;
	printf("До какого предела вести подсчет? Введите целое число:\n");
	n = get_int();
	for(i = 0; i <= n; i++)
		printf("%d\n", i);
	while(getchar() != '\n')
		continue;
}

char get_choice()
{
	int ch;
	printf("Введите букву, соответствующую выбранному варианту:\n");
	printf("c. совет	z. звонок\n" "p. подсчет	e. выход\n");
	ch = get_first();
	while(ch != 'c' && ch != 'z' && ch != 'p' && ch != 'e')
	{
		printf("Введите c, z, p или e.\n");
		ch = get_first();
	}
	return ch;
}

char get_first(void)
{
	int ch;
	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

int get_int(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" не является целочисленным.\nВведите целое число, такое как 25, -12 или 3: ");
	}
	return input;
}

