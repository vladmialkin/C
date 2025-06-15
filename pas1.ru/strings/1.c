/*Программа считывает, сколько раз встречается символ в строке
15.06.2025
Автор: Мялькин В.В.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    char c;
    int count = 0;
    
    printf("Введите строку: \n");
    fgets(s, sizeof(s), stdin);

    printf("Введите символ для поиска: \n");
    scanf("%c", &c);

    for(int i = 0; s[i] != EOF; i++)
    {
        if (s[i] == c)
            count++;
    }
    
    printf("Символ %c встречается %d раз.\n", c, count);
}
