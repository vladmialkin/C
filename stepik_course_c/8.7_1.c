/*Реализовать фукции работы с часами:
- after (Получает показание часов а и возвращает показание этих часов через min минут)
- forward (Переводит вперед стрелки часов на a.h часов и a.m минут
- backward (Переводит назад стрелки часов на a.h часов и a.m минут
- isEqualTime (Проверяет, совпадают ли показания часов a и b. Если совпадают, возвращает 1, если нет - 0
- printTic (Печатает показания часов в формате hh:mm\n

17.06.2025
Обновлено: 20.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>

typedef struct{
    int h; //часы
    int min; //минуты (от 0 до 59)
} TicTac;

TicTac after(TicTac, int min);

void forward(TicTac * me, TicTac a);
void backward(TicTac * me, TicTac a);
int isEqualTime(TicTac a, TicTac b);

void printTic(TicTac a);

int main()
{
    TicTac a, b, c;
    int mk;

    scanf("%d:%d", &(a.h), &(a.min));
    scanf("%d", &mk);
    scanf("%d:%d", &(b.h), &(b.min));
    
    printf("equal: %d\n", isEqualTime(a, b));
    c = after(a, mk);
    printf("after: ");
    printTic(c);

    c = a;
    printf("forward: ");
    forward(&a, b);
    printTic(a);
    
    printf("backward: ");
    backward(&c, b);
    printTic(c);
    
    return 0;
}

TicTac after(TicTac a, int min)
{
    TicTac res;
    res.h = (a.h + (min + a.min) / 60) % 12;
    res.min = (a.min + min) % 60;
    return res;
}

void forward(TicTac *me, TicTac a)
{
    me->h = (me->h + a.h + ((me->min + a.min) / 60)) % 12;
    me->min = (me->min + a.min) % 60;
}

void backward(TicTac *me, TicTac a)
{
    me->h = (12 + me->h - a.h - (me->min - a.min < 0)) % 12;
    me->min = (60 + me->min - a.min) % 60;
}

int isEqualTime(TicTac a, TicTac b)
{
    return a.h == b.h && a.min == b.min;
}

void printTic(TicTac a)
{
    printf("%02d:%02d\n", a.h, a.min);
}
