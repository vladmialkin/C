#include <stdio.h>
#include <stdlib.h>


int main()
{
    int k;
    int sum = 0, final_sum = 0;
    int flag = 0;
    
    int start_ind = -1, final_start_ind = -1;
    int final_end_ind = -1;
    int count = 0, final_count = 0;
    int *arr = malloc(1000 * sizeof(int));
    int i = 0, j = 0;
    printf("Введите числа массива:\n");
    while (1)
    {
        scanf("%d", &k);
        arr[i] = k;

        if (k == 0)
            break;
        else if ( k > 0 && i == 0){
            i++;
            continue;
        }
        else if (k < 0){
            if (flag){
                if (final_count < count){
                    final_sum = sum;
                    final_count = count;
                    final_start_ind = start_ind;
                    final_end_ind = i - 1;

                }
                sum = 0;
                count = 0;
                start_ind = -1;
            }
            flag = 1;
            i++;
            continue;   
        }
        
        if (flag == 1 && k > 0){
            if (start_ind == -1)
                start_ind = i;
            sum += k;
        }
        count++;
        i++;
    }
    if(final_sum == 0){
        printf("Получился неудачный массив.\n");
        abort();
    }

    printf("Максимальная сумма: %d\n", final_sum);
    printf("максимальное количество элементов\n", final_count);
    printf("Значение первого числа arr[%d] = %d\n", final_start_ind, arr[final_start_ind]);
    printf("Значение последнего числа arr[%d] = %d\n", final_end_ind, arr[final_end_ind]);
    printf("Массив цепочки: ");
    for(int i = final_start_ind; i <= final_end_ind; i++)
        printf("%d ", arr[i]);
}
