#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, k;
    int pos = -1;
    printf("Размер массива: \n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d элемент: ", i);
        scanf("%d", &k);
        arr[i] = k;
        if (k >= 0 && pos == -1)
            pos = i;
    }
    printf("\n");
    printf("первый положительный элемент:%d", arr[pos]);
    free(arr);
}
