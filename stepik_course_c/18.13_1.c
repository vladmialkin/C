/* Программа проверяет правильность последовательности из различных скобок.
Пусть скобочные структуры состоят из четырех различных пар скобок: () [] {} <>Открывающая и закрывающая скобки должны быть одного типа. 
Ваша задача - определить правильная ли скобочная структура.

Пустая последовательность является правильной. Если A – правильная, то последовательности (A), [A], {A}, <A> – правильные. 
Если A и B – правильные последовательности, то последовательность AB – правильная.

Для решения задачи нужно реализовать стек и помещать в него вводимые скобки. При добавлении очередной скобки нужно проверять:
- является ли вводимая скобка открывающей при отсуствии других скобок;
- является ли вводимая скобка симметричной последней скобке в стеке, если да - удаляем последнюю в стеке скобку, ничего не добавляем, если нет - добавляем скобку в стек;
Если стек стал пустым - последовательность правильная.
TODO
- Добавить проверку на ввод некоректных данных.
- Добавить моментальный вывод результата "NO" при закрывающихся скобках в начале, идущих первыми. 

26.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
typedef char Data;

typedef struct {
    unsigned int n;
    size_t size;
    Data *a;
} Stack;

Stack *stack_create();
void *stack_destroy(Stack *st);
void stack_push(Stack *st, Data x);
void stack_pop(Stack *st);
int stack_is_empty(Stack *st);
Data stack_get(Stack *st);

int main()
{
    char d;
    char buff[MAX_SIZE];
    Stack *st = stack_create();
    while(fgets(buff, MAX_SIZE, stdin) != NULL){
        buff[strcspn(buff, "\n")] = '\0';
        for(int i = 0; i < (int)strlen(buff); i++){
            if (!stack_is_empty(st)){
                d = stack_get(st);
                if (d + 1 == buff[i] || d + 2 == buff[i]){
                    stack_pop(st);
                }
                else{
                    stack_push(st, buff[i]);
                }
            }
            else{
                stack_push(st, buff[i]);
            }
        }
    }
    if (stack_is_empty(st))
        printf("YES\n");
    else
        printf("NO\n");
    st = stack_destroy(st);
    if (st != NULL){
        perror("Ошибка при очистке памяти стека.");
        exit(EXIT_FAILURE);
    }
    return 0;
}

Stack *stack_create()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    if (st == NULL){
        perror("Ошибка при веделении памяти для стека.");
        exit(EXIT_FAILURE);
    }
    st->n = 0;
    st->size = 4;
    st->a = (Data *)malloc(4 * sizeof(Data));
    if (st->a == NULL){
        perror("Ошибка при выделении памяти для массива стека.");
        exit(EXIT_FAILURE);
    }
    return st;
}

void *stack_destroy(Stack *st)
{
    if (st != NULL){
        if (st->a != NULL)
            free(st->a);
        free(st);
    }
    return NULL;
}

void stack_push(Stack *st, Data x)
{
    if (st->size == st->n){
        st->size *= 2;
        Data *tmp = realloc(st->a, st->size * sizeof(Data));
        if(!tmp){
            perror("Ошибка при добавлении памяти для массива.");
            exit(EXIT_FAILURE);
        }
        st->a = tmp; 
    }
    st->a[st->n] = x;
    st->n++;
}

void stack_pop(Stack *st)
{
    if (stack_is_empty(st)){
        perror("Ошибка при удалении элемента из пустого массива.");
        exit(EXIT_FAILURE);
    }
    st->n--;
}

int stack_is_empty(Stack *st)
{
    return st->n == 0;
}

Data stack_get(Stack *st)
{
    if (stack_is_empty(st)){
        perror("Ошибка получения элемента из пустого массива.");
        exit(EXIT_FAILURE);
    }
    return st->a[st->n - 1];
}
