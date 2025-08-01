/*Программа получает имя файла и имя его копии для последующего копирования данных.
Автор: Мялькин В.В.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100
#define BUF_SIZE 1024

void s_gets(char *, int);

int main(void)
{
    FILE *fa, *fs;
    char file_app[NAME_LEN];        //исходный файл
    char file_src[NAME_LEN];        //файл для копирования
    char buff[BUF_SIZE];
    puts("Введите имя исходного файла");
    s_gets(file_app, NAME_LEN);
    puts("Введите имя файла для копирования");
    s_gets(file_src, NAME_LEN);

    if((fa = fopen(file_app, "r")) == NULL){
        fprintf(stderr, "Ошибка при открытии файла %s.\n", file_app);
        exit(EXIT_FAILURE);
    }

    if((fs = fopen(file_src, "wb")) == NULL){
        fprintf(stderr, "Ошибка при открытии файла %s.\n", file_src);
        exit(EXIT_FAILURE);
    }

    while(fgets(buff, BUF_SIZE, fa))
        fwrite(buff, sizeof(char), BUF_SIZE, fs);

    if(ferror(fa) != 0){
        fprintf(stderr, "Ошибка при чтении из файла %s.\n", file_app);
        exit(EXIT_FAILURE);
    }
    
    if(ferror(fs) != 0){
        fprintf(stderr, "Ошибка при записи в файл %s.\n", file_src);
        exit(EXIT_FAILURE);
    }
    fclose(fa);
    fclose(fs);
    printf("Программа завершена.");
    return 0;
}

void s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
}