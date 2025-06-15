#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    int* arr;
    int count_one = 1, count_two = 1, count_even = 0, count_odd = 0;

    printf("Введите количество эелементво: \n");
    scanf("%d", &n);
    
    arr = malloc(n * sizeof(int));

    printf("Введите последовательность: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
        
        if (arr[i] > 0)
            count_even++;
        if (arr[i] < 0)
            count_odd++;        

        if (i > 1)
            if (arr[0] == arr[i])
                count_one++;
            else if (arr[1] == arr[i])
                count_two++;
    }
    
    if (count_one > count_two)
        printf("Больше элементов, равных первому - %d, количество - %d\n", arr[0], count_one);
    else if (count_one < count_two)
        printf("Больше элементов, равных второму - %d, количество - %d\n", arr[1], count_two);
    else
        printf("Элементы первого равны элементам второго.\n");

    if (count_even > count_odd)
        printf("Больше четных элементов: %d\n", count_even);
    else if (count_even < count_odd)
        printf("Больше нечетных элементов: %d\n", count_odd);
    else
        printf("Количество четных и нечетных одинаково.\n");
}
