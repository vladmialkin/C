/* Программа работает с RGB-форматом и выполняет следующие функции:
- считывание RGB-формата из консоли;
- перевод RGB-формата в число;
- Преобразование числа цвета в RGB-формат;
- Печать цвета в формате чисел;
- Печать цвета в HTML-формате;

20.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

Color getColor();
unsigned long long convertToHTML(Color);
Color convertToRGB(unsigned long long);
void printRGB(Color);
void printHTML(Color);

int main()
{
    Color z, z2;
    unsigned long long html;
    
    z = getColor();
    printRGB(z);
    
    html = convertToHTML(z);
    printf("%llu\n", html);
    printHTML(z);

    z2 = convertToRGB(html);
    printRGB(z2);

    return 0;
}

Color getColor()
{
    Color color;
    scanf("%hhd %hhd %hhd", &color.red, &color.green, &color.blue);
    return color;
}

unsigned long long convertToHTML(Color c){
    unsigned long long sum = 0;
    sum += c.red * 256 * 256;
    sum += c.green * 256;
    sum += c.blue;
    return sum;
}

Color convertToRGB(unsigned long long x)
{
    Color c;
    c.blue = x % 256;
    c.green = ((x - c.blue) / 256) % 256;
    c.red = x / 256 / 256 % 256;
    return c;
}

void printRGB(Color c)
{
    printf("%d %d %d\n", c.red, c.green, c.blue);
}

void printHTML(Color c)
{
    printf("%X%X%X\n", c.red, c.green, c.blue);
}
