#include <stdio.h>


int main(){
    int n;
    for(int i = 20; i <= 30; ++i){
        n = i;
        while (n != 1){
            if (n % 2 == 0)
                n = n / 2;
            else
                n = (3 * n + 1) / 2;
            printf("|%d| ", n);
        };
        printf("\n");
    };
}
