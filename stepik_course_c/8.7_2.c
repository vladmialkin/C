/*Программа поворачивает отрезок на плоскоси XY на 90 градусов по часовой стрелке вокруг точки (0;0) и печатает полученный отрезок и его длину.

18.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;
    Point b;
    float length;
} Line;

float distance(Point a, Point b);
void scanLine(Line *t);
void printLine(Line t);
void rotLine(Line *t);

int main()
{
    Line t;
    scanLine(&t);
    rotLine(&t);
    printLine(t);
    return 0;
}

float distance(Point a, Point b)
{
    float distance = sqrt((b.x - a.x) * (b.x - a.x) + (b.y -a.y) * (b.y - a.y));
    return distance;
}

void scanLine(Line *t)
{
    printf("Введите 2 точки с координатами:\n");
    if (scanf("%d%d %d%d",&t->a.x, &t->a.y, &t->b.x, &t->b.y) != 4){
        printf("Неверный ввод. Нужно вводить: x1 y1 x2 y2\n");
        abort();
    }
}

void printLine(Line t)
{
    printf("Line: (%d,%d) (%d,%d), length = %0.3f\n", t.a.x, t.a.y, t.b.x, t.b.y, t.length);
}

void rotLine(Line *t)
{
    int tmp;
    tmp = t->a.x * -1;
    t->a.x = t->a.y;
    t->a.y = tmp;
    
    tmp = t->b.x * -1;
    t->b.x = t->b.y;
    t->b.y = tmp;
    
    t->length = distance(t->a, t->b);
}

