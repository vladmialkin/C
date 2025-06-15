#include <stdio.h>
#include <stdlib.h>


int main()
{   
    int n, k;
    int old_value;
    int sum = 0, neg_sum = 0;
    int flag = 1;
    printf("Введите количество элементов массива\n");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    printf("Введите последовательность:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        arr[i] = k;
        if (i > 0)
            if (!(k > 0 && old_value < 0) && !(k < 0 && old_value > 0))
                flag = 0;
            sum += k;
            neg_sum += old_value;
        old_value = k;
    }
    if (flag)
        printf("Знакочередующая последовательность.\n");
    else
        printf("Не знакочередующая последовательность.\n");
    printf("Сумма положительных элементов: %d\n", sum);
    printf("Сумма отрицательных элементов: %d\n", neg_sum);
    printf("%d - %d = %d", sum, -1 * neg_sum, sum - neg_sum);
}
