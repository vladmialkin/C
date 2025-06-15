#include <stdio.h>

int main(){
    int numb;
    int factorial = 1;
    
    scanf("%d", &numb);
    for(int i = 1; i <= numb; ++i){
        factorial = factorial * i;
    };
    printf("%d! = %d", numb, factorial);
}
