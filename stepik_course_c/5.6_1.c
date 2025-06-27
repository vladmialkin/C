/* Программа возвращает точку координат зеркально относительно оси Y

16.06.2025
Автор: Мялькин В.В.*/
#include <stdio.h>

void mirror(int *px, int *py);

int main()
{
    int x, y;

    printf("Введите координату точки x и y:\n");
    scanf("%d%d", &x, &y);

    mirror(&x, &y);

    return 0;
}

void mirror(int *px, int *py)
{
    printf("%d %d\n", *px * -1, *py);
}
