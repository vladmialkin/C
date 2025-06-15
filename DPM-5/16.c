#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    int* arr;
    int sum = 0, final_sum = 0;
    int count = 0, final_count = 0;
    int old_val;

    printf("Введите количество элементов: \n");
    scanf("%d", &n);
    
    arr = malloc(n * sizeof(int));    
    
    printf("Введите последовательность: \n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
        if (i > 0)
            if (arr[i] == old_val)
            {
                sum+=arr[i];
                count++;
            }
            else
            {
                sum = arr[i];
                count = 1;
            }
        if (i == 0)
        {
            sum+=arr[i];
            count++;
        }
        if (count > final_count)
        {
            final_count = count;
            final_sum = sum;
        }
        old_val = arr[i];
    }
    printf("Максимальная сумма: %d, количество элементов - %d\n", final_sum, final_count);
}
