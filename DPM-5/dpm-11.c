#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_min(int arr[], int size);

int get_max(int arr[], int size);

int my_insert(int arr[], int len, int cap, int value, int pos);

void my_remove(int arr[], int* size);

void bubble_sort(int arr[], int size);

void selection_sort(int arr[], int size);

int my_find(int arr[], int size);

void set_sort(int arr[], int* size);

void print_array(int arr[], int size);

/*
Сделать функции вместо процедур
Добавить функцию insert, изменить имя текущей функции my_insert на replace
Сделать strip, который удаляет isspace
При проверке на перевыделение нужно исопльзовать временную переменную
Нужно выделять больше памяти, для более редкого ее выделения
Сделать функцию вывода массива
Переписать remove_duplicates, чтобы сохранился порядок элементов
Добавить слияние 2 массивов, вернуть упорядоченный массив
*/

int main()
{
    int n, k;
    int * arr;
    int cap;

    char buff[20];

    printf("Введите количество элементов.\n");
    scanf("%d", &n);

    arr = malloc(n * 2 * sizeof(int));
    cap = n * 2 * sizeof(int);
    if (arr == 0)
    {
        printf("Память не смогла выделиться.\n");
        abort();
    }

    printf("Введите массив.\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
    }

    while(1)
    {
        printf("Введите одну из команд:\n");
        printf("Найти минимальный элемент массива - min\n");
        printf("Найти максимальный элемент массива - mах\n");
        printf("Вставить элемент по индексу - insert\n");
        printf("Удалить элемент по индексу - remove\n");
        printf("Отсортировать массив методом Пузырька - bubble_sort\n"); 
        printf("Отсортировать массив методом выбора - selection_sort\n");
        printf("Поиск заданного элемента в массиве - find\n");
        printf("Удаление повторяющихся элементов в массиве - set_sort\n");
        printf("Выход - exit\n");
        
        fgets(buff, sizeof(buff), stdin);
        
        
        buff[strlen(buff) - 1] = '\0';     
        
        if (!strcmp(buff, "exit"))
            break;
        else if (!strcmp(buff, "min")){
            int min = get_min(arr, n);
            printf("Минимальное число - %d\n", min);
        }
        else if (!strcmp(buff, "max")){
            int max = get_max(arr, n);
            printf("Максимальное число - %d\n", max);
        }
        else if (!strcmp(buff, "insert")){
            int pos, value;
            printf("Введите индекс и значение для добавление в массив: \n");
            scanf("%d%d", &pos, &value);
            
            if (n + 1 > cap){
                cap*= 2;
                arr = realloc(arr, cap);
            }
            n = my_insert(arr, n, cap, value, pos);
            print_array(arr, n);
        }
        else if (!strcmp(buff, "remove"))
            my_remove(arr, &n);
        else if (!strcmp(buff, "bubble_sort"))
            bubble_sort(arr, n);
        else if (!strcmp(buff, "selection_sort"))
            selection_sort(arr, n);
        else if (!strcmp(buff, "find"))
        {
            int res = my_find(arr, n);
            if (res == -1)
                printf("Значение не найдено.\n");
            else
                printf("Искомое значение под индексом - %d\n", res); 
        }
        else if (!strcmp(buff, "set_sort"))
            set_sort(arr, &n);
    }
    free(arr);
}

int get_min(int arr[], int size)
{
    int min = arr[0];
    for(int i = 0; i < size; i++){
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int get_max(int arr[], int size)
{
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int my_insert(int arr[], int len, int cap, int value, int pos)
{
    if ((pos < 0) || (pos > len)){
        return -1;
    }
    if (len >= cap){
        return -1;
    }

    for(int i = len + 1; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    
    return len + 1;
}

void my_remove(int arr[], int *size)
{   
    int ind;
    
    printf("Введите индекс для удаления из массива.\n");
    if (scanf("%d", &ind) != 1)
    {
        printf("Не верный ввод.\n");
        abort();
    }
    
    if (ind < 0 || ind > (*size))
    {
        printf("Не верный индекс.\n");
        abort();
    }
    
    (*size)--;    
    arr = realloc(arr, (*size) * sizeof(int));    
    
    printf("Обновленный массив:\n");
    
    for(int i = ind; i < (*size); i++)
        arr[i] = arr[i+1];

    for(int i = 0; i < (*size); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sort(int arr[], int size)
{
    int tmp;
    int flag;

    printf("Сортировка методом Пузырька:\n");
    
    for(int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for(int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (!flag)
            break;
    }
    
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");    
}

void selection_sort(int arr[], int size)
{
    int tmp;    

    printf("Сортировка методом выбора.\n");

    for(int i = 0; i < size - 1; i++)
    {
        int min_ind = i;
        for(int j = i + 1; j < size; j++)
        {
            if (arr[min_ind] > arr[j])
                min_ind = j;
        }
        if (min_ind != i)
        {
                tmp = arr[i];
                arr[i] = arr[min_ind];
                arr[min_ind] = tmp;
        }
    }

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int my_find(int arr[], int size)
{   
    int val;

    printf("Введите значения для поиска в массиве.\n");

    if (scanf("%d", &val) != 1)
    {
        printf("Не верный ввод.\n");
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
        if (val == arr[i])
            return i;
    }
    return -1;
}

void set_sort(int arr[], int* size)
{
    bubble_sort(arr, *size);

    int unique_count = 1;

    for (int i = 1; i < (*size); i++)
    {
        if(arr[i] != arr[i - 1])
            arr[unique_count++] = arr[i];
    }
    
    arr = realloc(arr, unique_count * sizeof(int));
    (*size) = unique_count;

    printf("Массив без повторов.\n");
    for(int i = 0; i < (*size); i++)
        printf("%d ", arr[i]);
    printf("\n");
}   

void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
