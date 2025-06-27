/* Программа делит четные и нечетные символы по разным строкам 
Программа проверяет четность и нечетность индекса символа в строки.
15.06.2025
Автор: Мялькин В.В.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], str3[100];
    int j = 0, k = 0;
    printf("Введите строку: \n");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1) - 1] = '\0'; //убирает \n из строки TODO переделать удаление \n

    for(int i = 0; i < strlen(str1); i++){
        if (i % 2 == 0){
            str3[k++] = str1[i];
        }
        else{
            str2[j++] = str1[i];
        }
    }
    str2[j] = '\0';
    str3[k] = '\0';
    printf("Начальная строка: \n");
    puts(str1);
    
    printf("Строка с нечетными символами: \n");
    puts(str2);
    printf("Строка с четными символами: \n");
    puts(str3);
}
