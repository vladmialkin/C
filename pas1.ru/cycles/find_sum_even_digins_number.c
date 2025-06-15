#include <stdio.h>


int main(){
    int n;
    int sum, res;
    scanf("%d", &n);
    while(n != 0){
        res = n % 10;
        if (res % 2 == 0)
            sum += res;
        n = n / 10;
    };
    printf("%d", sum);
}
