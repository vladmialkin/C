#include <stdio.h>
#include <stdlib.h>

typedef struct tag_obj {
    int data;
    struct tag_obj * next;
} OBJ;


OBJ * push(OBJ * top, int data)
{
    OBJ * ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ * pop(OBJ * top)
{
    if (top == NULL)
        return top;
    printf("Минимальный элемент: %d\n", top->data);
    
    OBJ * ptr_next = top->next;
    free(top);
    
    return ptr_next;
}

int main()
{
    int n, k;
    int * arr;
    int min;
    OBJ * top = NULL;
    
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    
    arr = malloc(n * sizeof(int));

    printf("Введите последовательность элементов\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
        if ( i == 0 || min > k)
        {
            min = k;
            top = push(top, min);
        }
    }

    for(int i = 0; i < 3; i++)
        top = pop(top);
}
