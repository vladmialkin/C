#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, k;
    int sum = 0;
    int pr = 1;
    printf("Размер массива: \n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d элемент: ", i);
        scanf("%d", &k);
        arr[i] = k;
        sum += k;
        pr *= k;
    }
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("сумма: %d, произведение: %d", sum, pr);
    free(arr);
}
