#include <stdio.h>


int main(){
    int a, b, res1, res2;
    scanf("%d%d", &a, &b);
    while(a > 0){
        res1 = a % 10;
        while(b > 0){
            res2 = b % 10;
            if (res1 == res2){
                printf("%d ", res1);
                break;
            };
            b = b / 10;
        };
        a = a / 10;
    };
}
