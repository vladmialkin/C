/* Программа предлагает ввести имя файла и считывает данные из него.
Автор: Мялькин В.В.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

void get_filename(char *, int);

int main(void)
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char filename[MAX_NAME];
    puts("Введите имя файла.");
    get_filename(filename, MAX_NAME);
    if((fp = fopen(filename, "r")) == NULL){
        fprintf(stderr, "Ошибка чтения файла %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF){
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("Файл %s содержит %lu символов\n", filename, count);
    return 0;
}

void get_filename(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
}