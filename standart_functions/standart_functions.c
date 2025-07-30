/*Реализация популярных стандартных функций работы со строками*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "standart_functions.h"

//выводит строку
void put1(const char *string)
{
	while(*string) 			//*string != NULL
		putchar(*string++); 	//*(string++)
}

//выводит строку и подсчитывает символы
int put2(const char *string)
{
	int count = 0;
	while(*string){ 
		putchar(*string++);
		count++;
	}
	putchar('\n'); 			// не учитывается при подсчете
	return (count);
}

//объединяет 2 строки
char *str_cat(const char *s1, const char *s2, int *len)
{
	/* Функция получает указатели на строки, вычисляет их длинну и создает результирующую строку, куда по одному символу заносит строки */
	int i = 0;
	*len = strlen(s1) + strlen(s2) + 1;
	char *res = (char *)malloc(*len * sizeof(char));
	if (res == NULL){
		perror("failed malloc in str_cat");
		exit(EXIT_FAILURE);
	}

	while(*s1 != '\n' && *s1 != '\0'){
		if (*s1 == '\n')
			continue;
		res[i++] = *s1;
		*s1++;
	}

	while(*s2 != '\n' && *s2 != '\0'){
		if (*s2 == '\n')
			continue;
		res[i++] = *s2;
		*s2++;
	}
	res[i] = '\0';
	return res;
}

char *str_cat2(const char *s1, const char *s2)
{
	int len = strlen(s1) + strlen(s2) + 1;
	char *res = (char *)malloc(len *sizeof(char));
	strcpy(res, s1);
	strcpy(res + strlen(s1), s2);
	return res;
}

//сравнивает строки
int str_cmp(const char *s1, const char *s2)
{
	while(*s1 && *s2){
		if (*s1++ != *s2++)
			return -1;
	}
	return 0;
}

//сравнивает строки до n числа
int str_ncmp(const char *s1, const char *s2, int limit)
{
	while(*s1 && *s2 && limit != 0){
		if (*s1++ != *s2++)
			return -1;
		limit--;
	}
	return 0;
}

//копирует строку в строку
char *str_cpy(char *s1, const char *s2)
{
	while(*s1)
		*s1++;
	while(*s2)
		*s1++ = *s2++;
	return s1;
}

//копирует строку в строку до n элементов
char *str_ncpy(char *s1, const char *s2, int n)
{
	while(*s1)
		*s1++;
	while(*s2 && n != 0){
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return s1;
}

//возвращает указатель на первую ячейку из s1, в которой содержится символ ch
char *str_chr(const char *s1, const char ch)
{
	while(*s1)
		if (*s1 == ch)
			return (char *)s1;
	return NULL;
}


