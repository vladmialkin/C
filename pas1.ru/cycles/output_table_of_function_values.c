#include <stdio.h>

int main(){
    float step = 0.5;
    printf("x\t|y\n");
    for(float i = -5; i <= 5; i = i + step){
        printf("%0.2f\t|%0.2f\n", i, 5 - i*i/2);
    };
}
