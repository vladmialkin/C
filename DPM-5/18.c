#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, size;
    int* arr;

    printf("Введите количество элементов: \n");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));
    
    printf("Введите последовательность, состоящую только из 0 и 1: \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        //if (k != 0 || k != 1)
        //{
        //    printf("Неверный элемент: %d, должно быть 0 или 1.\n",k);
        //    abort();
        //}
        arr[i] = k;
    }

    printf("Введите длину для поиска последовательности из 0.\n");
    scanf("%d", &size);

    if (size > n)
    {
        printf("Длина больше размера последовательности.\n");
        abort();
    }

    for(int i = 0, j = size; i < n; i++)
    {
        if (arr[i] == 0)
            j--;
        else
            j = size;

        if (j == 0)
        {
            printf("Последовательность из 0 длиной %d существует.\n", size);
            break;
        }

        if (i == n - 1)
            printf("ПОследовательности из 0 длиной %d не существует.\n", size);
    }
}
