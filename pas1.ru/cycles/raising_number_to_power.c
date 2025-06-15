#include <stdio.h>
#include <stdlib.h>


int main(){
    float n;
    int p;
    float res;
    scanf("%f%d", &n, &p);
    res = 1;
    
    if (p >= 0){
        for(int i = 1; i<= p; ++i){
            res = res * n;
        };
    }
    else{
        for(int i = 1; i <= (p * -1); ++i){ 
            res = res * n;
        };
        res = 1 / res;
    };
    printf("%f", res);
}
