#include <stdio.h>
#include <stdlib.h>


int main(){
    int a, b;
    int res;
    res = scanf("%d%d",&a,&b);
    if (res != 2){
        printf("Неверно введены числа a и b.");
        abort();
    };
    
    for(int i = a; i <= b; ++i){
        printf("%d в кубе = %d\n", i, i*i*i);
    };
}
