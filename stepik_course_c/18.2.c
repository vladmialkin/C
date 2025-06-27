/* Повторение реализации стека на основе динамического массива.
Реализовать следующие функции:
- void stack_init (Stack * s); - необходимые действия для создания и инициализации стека. (Когда мы создаем локальную переменную, то она не инициализируется 0, т.е. в поле n может лежать любое число.)
- void stack_push (Stack * s, Data x); - кладет число х в стек;
- Data stack_pop (Stack * s); - достает одно число из стека и возвращает его
- Data stack_get (Stack * s); - возвращает число, лежащее на верхушке стека, не изменяя состояния стека;
- void stack_clear (Stack * s); - очищает стек (функция stack_is_empty должна вернуть 1).
- void stack_print (Stack * s); - распечатывает через пробел числа, лежащие в стеке. С самого первого до верхнего. В конце переводит строку.
- int stack_size (Stack * s); - возвращает количество элементов, лежащих в стеке
- int stack_is_empty (Stack * s); - возвращает 1 если стек пуст, иначе возвращает 0.
- int stack_is_full (Stack * s); - возвращает 1 если стек полон (в него нельзя добавлять данные, это приведет к переполнению), иначе возвращает 0.
26.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 8

typedef int Data;

typedef struct {
    Data * a;          // место для хранения данных
    unsigned int n;     // количество хранимых данных
    size_t size;        // сколько выделено памяти
} Stack;

void stack_push(Stack *s, Data x);
Data stack_pop(Stack *s);
Data stack_get(Stack *s);
void stack_clear(Stack *s);
void stack_print(Stack *s);
int stack_size(Stack *s);
int stack_is_empty(Stack *s);
int stack_is_full(Stack *s);
Stack * stack_create(int size);
Stack * stack_destroy(Stack *s);

int main()
{
    Stack *st = stack_create(N);
    int d;
    Data test[] = {44, -3, 17, 5, 9, 8, 11, 88};
    
    
    // тесты для init
    assert(st->n == 0);

    // тесты для push
    for(int i = 0; i < N; i++){
        d = test[i];
        printf("push: %d\n", d);
        stack_push(st, d);
        stack_print(st);
        printf("is_empty: %s\n", stack_is_empty(st) ? "YES": "NO"); 
        printf("is_full: %s\n", stack_is_full(st) ? "YES": "NO"); 
    }
    // тесты для get
    d = stack_get(st);
    assert(test[N - 1] == d);
    
    // тесты для size
    d = stack_size(st);

    // тесты для clear
    stack_clear(st);
    assert(stack_is_empty(st) == 1);
    assert(st->size == 0);
    
    for(int i = 0; i < N; i++){
        stack_push(st, test[i]);
    }

    // тесты для pop
    //for(int i = 0; i < N; i++){
    //    d = stack_pop(st);
    //    printf("pop: %d\n", d);
    //    stack_print(st);
    //    printf("is_empty: %s\n", stack_is_empty(st) ? "YES": "NO"); 
    //    printf("is_full: %s\n", stack_is_full(st) ? "YES": "NO"); 
    //}
    
    // тесты для destroy
    if (NULL == stack_destroy(st))
        printf("end\n");
    return 0;
}

void stack_push(Stack *s, Data x)
{
    if (s->n == s->size){
        s->size *= 2;
        Data *tmp = realloc(s->a, s->size * sizeof(Data));
        if (!tmp){
            perror("Ошибка увеличения размера массива.");
            exit(EXIT_FAILURE);
        }
        s->a = tmp;
    }
    s->a[s->n++] = x;
}

Data stack_pop(Stack *s)
{
    if (stack_is_empty(s)){
        perror("Ошибка извлечения элемента из пустого стека.");
        exit(EXIT_FAILURE);
    }
    return s->a[--s->n];
}

Data stack_get(Stack *s)
{
    if (stack_is_empty(s)){
        perror("Ошибка получения элемента из пустого списка.");
        exit(EXIT_FAILURE);
    }
    return s->a[s->n - 1];
}

void stack_clear(Stack *s)
{
    if (s->a != NULL){
        free(s->a);
        s->a = NULL;
    }
    s->n = 0;
    s->size = 0;
}

void stack_print(Stack *s)
{
    for(unsigned int i = 0; i < s->n; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}

int stack_size(Stack *s)
{
    return s->n;
}

int stack_is_empty(Stack *s)
{
    return s->n == 0;
}

int stack_is_full(Stack *s)
{
    return s->n == (unsigned int)s->size;
}

Stack * stack_create(int size)
{
    Stack * s = malloc(sizeof(Stack));
    if(!s){
        perror("Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }
    s->n = 0;
    s->size = size;
    Data *tmp = malloc(size * sizeof(Data));
    if (!tmp){
        perror("Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }
    s->a = tmp;
    return s;
}

Stack * stack_destroy(Stack *s)
{
    if (s != NULL){
        stack_clear(s);
        free(s);
    }
    return NULL;
}























