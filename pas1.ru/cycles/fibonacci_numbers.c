#include <stdio.h>

int main(){
    int n, a, b, c;
    scanf("%d", &n);
    a = 0;
    b = 1;
    
    for(int i = 3; i <= n; i++){
        c = b;
        b = a + b;
        a = c;
        printf("%d ", b);
    }
}
