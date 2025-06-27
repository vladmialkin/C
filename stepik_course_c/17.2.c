/* Программа заменяет подстроку в строке с использованием динамической памяти.

25.06.2025
Автор Мялькин В.В.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

char * replace(const char *s);

int
main()
{
    char s[N];
    char *d;
    while (NULL != fgets(s, N, stdin)){
        d = replace(s);
        printf("+++%s+++\n", d);
        free(d);
    }
    return 0;
}

char * replace(const char *src)
{
    char *s = (char *)src;
    size_t len_src = strlen(src);    

    char *res = malloc(len_src);
    if (!res){
        perror("Ошибка выделения памяти.");
        exit(EXIT_FAILURE);
    }

    char *p = strstr(s, "bomb");
    while (p != NULL){
        *p = '\0';
        strcat(res, s);
        char *new_res = realloc(res, len_src - strlen("bomb") + strlen("watermelon") + 1);
        if (new_res != NULL)
            res = new_res;
        else {
            printf("Ошибка при перевыделении памяти.\n");
            abort();
        }
        strcat(res, "watermelon");
        s = p + strlen("bomb");
        p = strstr(s, "bomb"); 
    }
    strcat(res, s);
    return res;
}
