#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1, 2, 3, 5, 3, 9, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    int el1 = arr[0], el2 = arr[1];    

    for(int i = 1; i < length - 1; i++){
        if (el1 < el2)
            printf("%d ", el2);
        el1 = arr[i];
        el2 = arr[i + 1];
    }
}
