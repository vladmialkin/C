#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, k;
    int * arr;
    int min;
    int count; //количество элементов, которые больше по модулю своего индекса.
        
    printf("Введите количество элементов: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;

        if (i == 0)
            min = k;
        
        if (min > k)
            min = k;
    
        if (i < abs(k))
            count++;
    }
    printf("Минимальное число - %d\n", min);
    printf("Количество элементов, которые больше по модулю своего индекса - %d\n", count);
}
