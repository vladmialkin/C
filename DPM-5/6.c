#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    int *arr;
    int min, max;
    int count_min = 0;
    int count_max = 0; //колличество элементов, не равных максимальному

    printf("Введите количество переменных последовательности: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        arr[i] = k;
        
        if (i == 0){
            min = k;
            max = k;
        }

        if (min > k)
            min = k;
        if (max < k)
            max = k;
    }
    
    for(int i = 0; i < n; i++){
        if (arr[i] == min)
            count_min++;
        if (arr[i] < max)
            count_max++;
    }
    printf("Минимальный элемент: %d\n", min);
    printf("Количество минимальных элементов: %d\n", count_min);
    printf("Максимальный элемент: %d\n", max);
    printf("Количество элементов, меньше максимального: %d\n", count_max);
}
