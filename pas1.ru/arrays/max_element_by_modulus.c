#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, k, modul;
    int max = -999999;
    int max_ind;
    printf("Размер массива: \n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d элемент: ", i);
        scanf("%d", &k);
        arr[i] = k;
        modul = (k < 0) ? k * -1: k;
        if (max < modul){
            max = modul;
            max_ind = i;
        }
    }
    printf("\n");
    printf("max abs: %d", arr[max_ind]);
    free(arr);
}
