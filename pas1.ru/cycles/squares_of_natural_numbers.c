#include <stdio.h>
#include <stdlib.h>



int main(){
    int number, res;
    res = scanf("%d", &number);
    if (res != 1){
        printf("Неверный ввод числа.");
        abort();
    };

    for(int i = 0; i < number; ++i){
        printf("%d ",i*i);
    }
}
