#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, b, k;
    int sum1 = 0, sum2 = 0;
    printf("Размер массива: \n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d элемент: ", i);
        scanf("%d", &b);
        arr[i] = b;
    }
    printf("\nВведите индекс массива:\n");
    scanf("%d", &k);
    for(int i = 0; i < n; i++){
        if (i <= k)
            sum1 += arr[i];
        else
            sum2 += arr[i];
    }
    printf("сумма до %d: %d, сумма после: %d", k, sum1, sum2);
    free(arr);
}
