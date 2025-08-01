/* Программа добавляет содержимое из списка файлов в конец указанного файла */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fa, *fs;          //fa для файла назначения, fs для исходного файла
    int files = 0;          //количество добавляемых файлов
    char file_app[SLEN];    //имя файла назначения
    char file_src[SLEN];    //имя исходного файла
    int ch;

    puts("Введите имя файла назначения");
    s_gets(file_app, SLEN);

    if((fa = fopen(file_app, "a+")) == NULL){
        fprintf(stderr, "Не удалось открыть файл %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0){
        fputs("Не удается создать выходной буфер", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Введите имя первого исходного файла  (или пустую строку для завершения):");
    while(s_gets(file_src, SLEN) && file_src[0] != '\0'){
        if(strcmp(file_src, file_app) == 0)
            fputs("Добавить файл в конец самого себя невозможно\n", stderr);
        else if((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Не удается открыть файл %s\n", file_src);
        else{
            if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0){
                fputs("Не удается создать входной буфер", stderr);
                continue;
            }

            append(fs, fa);
            if(ferror(fs) != 0)
                fprintf(stderr, "Ошибка при чтении файла %s\n", fs);
            if(ferror(fa) != 0)
                fprintf(stderr, "Ошибка при записи файла %s\n", fa);
            fclose(fs);
            files++;
            printf("Содержимое файла %s добавлено.\n", file_src);
            puts("Введите следующее имя файла (или пустую строку для завершения):");
        }
    }
    printf("Добавление завершено. Количество добавленных файлов: %d\n", files);
    rewind(fa);
    printf("Содержимое %s:\n", file_app);
    while((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("\nОтображение завершено.");
    fclose(fa);
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0){
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

char *s_gets(char *st, int n)
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
    return ret_val;
}