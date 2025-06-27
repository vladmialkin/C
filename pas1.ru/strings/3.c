/* Программа подсчитывает количество цифр в строке
Программа берет символ строки и проверяет его через isdigit.
15.06.2025
Автор: Мялькин В.В.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int count = 0; //количество цифр
    
    printf("Введите строку: \n");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0'; // TODO переделать замену \n на \0
    
    for(int i = 0; str[i] != '\0'; i++){
        if (isdigit(str[i])){
            count++;
        }
    }

    printf("Количество цифр: %d\n", count);
}
