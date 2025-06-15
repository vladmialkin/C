#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    int min_count = 0; //количество локальных минимумов
    int max_count = 0; //количество локальных максимумов
    int * arr;    

    printf("Введите количество элементов\n");
    scanf("%d", &n);
    arr = malloc(n * sizeof(int));    
    
    printf("Введите последовательность чисел.\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
    }

    for(int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
            min_count++;
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            max_count++;
    }

    printf("Количество локальных минимумов %d\n", min_count);
    printf("Количество локальных максимумов %d\n", max_count);
}
