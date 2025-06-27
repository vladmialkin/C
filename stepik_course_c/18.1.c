/* Реализация стека на основе массива.
Стек будет фиксированного размера.
25.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <assert.h>
#define N 8

typedef int Data;

typedef struct {
    Data a[N];      //место для хранения данных
    unsigned int n; //сколько данных хранится
} Stack;

void print(Stack *s);
void init(Stack *s);
void push(Stack *s, Data data);
Data pop(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);

int
main()
{
    Stack stack;
    Stack * st = &stack;
    
    init(st);
    print(st);

    Data test[] = {5, 17, -3, 0, 1, 2, 3, 4};

    //тесты на длину стека
    assert(sizeof(test) == sizeof(st->a));
    Data d;

    //тесты для push
    for (int i = 0; i < N; i++){
        d = test[i];
        printf("push %d :", d);
        push(st, d);
        print(st);
        printf("empty: %s\n", is_empty(st) ? "YES": "NO");
        printf("full: %s\n", is_full(st) ? "YES": "NO");
    }

    //тесты для pop
    for(int i = 0; i < N; i++){
        d = pop(st);    // pop 5: 
        printf("pop %d: ", d);
        print(st);
    }
    //тесты для is_empty
    printf("empty: %s\n", is_empty(st) ? "YES": "NO"); // YES

    //тесты для is_full
    printf("full: %s\n", is_full(st) ? "YES": "NO");
    return 0;
}

void print(Stack *s)
{
    for(unsigned int i = 0; i < s->n; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}

void init(Stack *s)
{
    s->n = 0;
}

void push(Stack *s, Data data)
{
    s->a[s->n] = data;
    s->n++;
}

Data pop(Stack *s)
{
    s->n--;
    Data res = s->a[s->n];
    return res;
}

int is_empty(Stack *s)
{
    return s->n == 0;
}

int is_full(Stack *s)
{
    return s->n == N;
}
