#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    int * arr;
    int count = 0;
    int max_count = 0; 
    
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    
    arr = malloc(n * sizeof(int));
    
    printf("Введите последовательность из нулей и единиц.\n");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
        if (k == 0)
            count++;
        else
        {
            if (max_count < count)
                max_count = count;
            count = 0;
        }
    }
    printf("Длина максимальной последовательности из нулей - %d\n", max_count);
}
