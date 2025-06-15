#include <stdio.h>


int main(){
    int numb, res;
    scanf("%d", &numb);
    
    while (numb != 0){
        printf("%d ", numb % 10);
        numb = numb / 10;
    };
}
