#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, k;
    int sum = 0;
    printf("Размер массива: \n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d элемент: ", i);
        scanf("%d", &k);
        arr[i] = k;
        if (k >= 0)
            sum += k;
    }
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("сумма положительных элементов: %d", sum);
    free(arr);
}
