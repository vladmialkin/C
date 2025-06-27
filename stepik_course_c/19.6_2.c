/* Программа реализует стек на основе односвязного списка.
Реализовать следующие функции:
struct Node * list_create (); - необходимые действия для создания и инициализации списка (просто вернуть NULL).
void list_push (struct Node ** plist, Data x); - кладет число х первым элементом списка.
Data list_pop (struct Node ** plist); - достает первое число из списка и возвращает его.
Data list_get (struct Node * list); - возвращает число, лежащее в первом узле, не изменяя состояния списка.
void list_print (struct Node * list); - распечатывает через пробел числа, лежащие в списке. С самого первого до последнего. В конце переводит строку. 
Полезна для отладки прочих функций.
int list_size (struct Node * list); - возвращает количество элементов, лежащих в списке.
int list_is_empty (struct Node * list); - возвращает 1, если список пустой; иначе возвращает 0.
void list_clear (struct Node ** plist); - опустошает список, освобождая память. После этого можно опять добавлять элементы в список.

27.06.2025
Мялькин В.В.*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Data;

typedef struct Node{
    Data val;           //значение 
    struct Node *next;  //указатель на следующий элемент списка
} Node;

Node *list_create();
void list_push(Node **plist, Data x);
Data list_pop(Node **plist);
Data list_get(Node *list);
void list_print(Node *list);
int list_size(Node *list);
int list_is_empty(Node *list);
void list_clear(Node **plist);

void test0()
{
    struct Node * list = list_create();
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    list_push(&list, 21);
    list_print(list);                               // 21
    list_push(&list, 17);
    list_print(list);                               // 17 21
    list_push(&list, 3);
    list_print(list);                               // 3 17 21
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 0
    printf("size = %d\n", list_size(list));         // size = 3

    Data x = list_pop(&list);
    printf("pop %d\n", x);                          // pop 3
    list_print(list);                               // 17 21
    printf("size = %d\n", list_size(list));         // size = 2

    list_clear(&list);
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0
}

int main()
{
    test0();
    return 0;
}

Node *list_create()
{
    Node *list = NULL;
    return list;
}

void list_push(Node **plist, Data x)
{
    Node *p = malloc(sizeof(Node));
    if (p == NULL){
        perror("Ошибка выделения памяти для списка.");
        exit(EXIT_FAILURE);
    }
    p->val = x;
    p->next = *plist;
    *plist = p;
}

Data list_pop(Node **plist)
{
    if (*plist != NULL){
        Node *p = *plist;
        Data res = p->val;
        *plist = p->next;
        free(p);
        return res;
    }
    else{
        perror("Ошибка удаления жлемента из пустого списка.");
        exit(EXIT_FAILURE);
    }
}

void list_print(Node *list)
{
    for(Node *p = list; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");
}

Data list_get(Node *list)
{
    if (list != NULL)
        return list->val;
    else{
        perror("Ошибка получения элемента из пустого списка.");
        exit(EXIT_FAILURE);
    }
}

int list_size(Node *list)
{
    int count = 0;
    for(Node * p = list; p != NULL; p = p->next, count++)
        ;
    return count;
}

int list_is_empty(Node *list)
{
    return list == NULL;
}

void list_clear(Node **plist)
{
    Node *current = *plist;
    while(current != NULL){
        Node *next_node = current->next;
        free(current);
        current = next_node;
    }
    *plist = NULL;
}


