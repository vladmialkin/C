#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for(int i = 0; i < length; i++)
        if (max < arr[i])
            max = arr[i];
    for(int i = 0; i < length; i++)
        printf("%f ", arr[i] / (float)max);
}
