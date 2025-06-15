#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    int min = -1;
    printf("Введите время(0 - конец очереди).\n");
    while(1){
        scanf("%d", &n);
        if (n < 0){
            printf("Время должно быть положительным числом.");
            abort();
        }
        else if (n == 0)
            break;

        if (min > n || min == -1)
            min = n;
    }
    printf("Минимальное время: %d\n", min);
}
