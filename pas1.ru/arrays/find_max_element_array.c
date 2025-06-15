#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, k;
    int max = -999999;
    printf("Размер массива: \n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d элемент: ", i);
        scanf("%d", &k);
        arr[i] = k;
        if (max < k)
            max = k;
    }
    printf("\n");
    printf("max: %d", max);
    free(arr);
}
