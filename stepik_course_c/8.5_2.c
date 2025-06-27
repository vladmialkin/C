/*Пример готового кода. Написать функции, которые переводят время в часах и минутах в минуты с 0:00, а потом обратно.
Определим структуру Time с полями h(часы) и m(минуты).
17.05.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <assert.h>

typedef struct Time{
    int h; //часы
    int m; //минуты
} Time;

void print_time(Time t);

int time2min(Time t);
Time min2time(int mm);
Time add(Time t1, Time t2);

int main()
{
    Time t1 = {22, 55};
    Time dt = {2, 7};
    Time t2 = {1, 2};

    print_time(t1);
    print_time(dt);
    
    t2 = add(t1, dt);
    print_time(t2);
    
    return 0;
}

void print_time(Time t)
{
    printf("%02d:%02d\n", t.h, t.m);
}

int time2min(Time t)
{
    return t.h * 60 + t.m;
}

Time min2time(int mm)
{
    Time res;
    res.m = mm % 60;
    res.h = mm / 60 % 24;
    return res;
}

Time add(Time t1, Time t2)
{
    int mmres = time2min(t1) + time2min(t2);
    Time res = min2time(mmres);
    return res;
}
