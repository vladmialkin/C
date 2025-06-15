#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int n, k;
    int *arr;
    int old_val;
    int flag = 1; //флаг для проверки возрастающая ли последовательность
    int count = 0; //счетчик, который считает количество элементов, которые мешают стать возрастающей последовательностью
    int ind = -1; //индекс элемента, который мешает стать возрастающей последовательностью

    printf("Введите количество переменных последовательности: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        arr[i] = k;
        if (i > 0){
            if (k < old_val && i == 1){
                count++;
                ind = i - 1;
                flag = 0;
            }
            else if (k < old_val){
                count++;
                ind = i;
                flag = 0;
            }
        }
        old_val = k;            
    }
    if (flag)
        printf("Возрастающая последовательность\n");
    else
        printf("Не возрастающая последовательность\n");

    switch (count){
    case 0: 
        printf("Нет мещающих элементов\n");
        break;
    case 1:
        printf("Мешающий элемент под индекстом %d - %d\n", ind, arr[ind]);
        break;
    default:
        printf("Мешающих элементов больше 1.\n");
    }
}
