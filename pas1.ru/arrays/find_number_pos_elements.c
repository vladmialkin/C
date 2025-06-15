#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for(int i = 0; i < length; i++){
        if (arr[i] > 0){
            printf("%d ", arr[i]);
            count += 1;
        }
    }
    printf("\ncount pos values: %d", count);
}
