/*Программа предназначена для чтения бинарных файлов в текстовом режиме.
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
    FILE *fp;
    char filename[NAME_LEN];
    char buff[BUF_SIZE];
    puts("Введите имя файла для чтения.");
    s_gets(filename, NAME_LEN);

    if((fp = fopen(filename, "rb")) == NULL){
        fprintf(stderr, "Ошибка при открытии файла %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    while(fread(buff, sizeof(char), BUF_SIZE, fp) > 0){
        fputs(buff, stdout);
    }
    printf('\n');
    puts("Программа завершена.");
    return 0;
}

void s_gets(char *st, int n)
{
    char *find;
    
    if(fgets(st, n, stdin) != NULL){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
}