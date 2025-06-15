#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    int max = arr[0];
    for(int i = 0; i < length; i++){
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    printf("min: %d, max: %d, dif: %d", min, max, max - min);
}
