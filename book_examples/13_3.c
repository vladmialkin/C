/*Программа копирования файлов из 13_2, но со следующими отличиями:
- При копировании программа должна использовать функцию toupper для перевода текста в верхний регистр во время записи в выходной файл;
- Применяется текстовый режим.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 100
#define BUF_SIZE 1024

void s_gets(char *, int);
void append(FILE *, FILE *);

int main(void){
    FILE *fa, *fp;
    char file_app[NAME_LEN];        //исходный файл
    char file_src[NAME_LEN];        //файл для копирования

    puts("Введите имя исходного файла.");
    s_gets(file_app, NAME_LEN);

    puts("Введите имя файла для копирования.");
    s_gets(file_src, NAME_LEN);

    if((fa = fopen(file_app, "r")) == NULL){
        fprintf(stderr, "Ошибка открытия файла %s.\n", file_app);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(file_src, "w")) == NULL){
        fprintf(stderr, "Ошибка открытия файла %s.\n", file_src);
        exit(EXIT_FAILURE);
    }

    append(fa, fp);

    if(ferror(fa) != 0){
        fprintf(stderr, "Ошибка при чтении файла %s.\n", file_app);
        exit(EXIT_FAILURE);
    }

    if(ferror(fp) != 0){
        fprintf(stderr, "Ошибка при записи в файл %s.\n", file_src);
        exit(EXIT_FAILURE);
    }

    fclose(fa);
    fclose(fp);
    puts("Файлы скопированы. Завершение программы.");
    return 0;
}

void s_gets(char *st, int n)
{
    char *find;
    if(fgets(st, n, stdin)){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\0')
                continue;
    }
}

void append(FILE *source, FILE *dest)
{
    char ch;
    while((ch = fgetc(source)) != EOF){
        fputc(toupper(ch), dest);
    }
}