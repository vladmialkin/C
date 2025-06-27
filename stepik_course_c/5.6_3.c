/* Программа сдвигает точку с координатами x и y на dx и dy.
16.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>

void move(int *px, int *py, int dx, int dy);

int main()
{
    int x, y, dx, dy;
    
    printf("Координаты точки: \n");
    scanf("%d%d", &x, &y);
    printf("Координаты сдвига: \n");
    scanf("%d%d", &dx, &dy);

    move(&x, &y, dx, dy);
    return 0;
}

void move(int *px, int *py, int dx, int dy)
{
    printf("%d %d\n", *px + dx, *py + dy);
}
