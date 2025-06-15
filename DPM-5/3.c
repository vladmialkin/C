#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = malloc(1000 * sizeof(char));
    char c;
    int flag = 0;
    int x = 0;
    int count = 0; 
    int res;
    printf("Введите последовательность из l - легковых и m - грузовых машин:\n");
    while(1){
        res = scanf("%c", &c);
        if (res != 1){
            printf("Вводить нужно по 1 машине");
            abort();
        }
        if (c == 'l'){
            flag = 1;
            x++;
            continue;
        }
        else if (c == 'd' && flag)
            count++;
        if (x == 2){
            printf("Количество грузовых машин: %d", count);
            break;
        }
    }

}
