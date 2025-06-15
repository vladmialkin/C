#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], max = arr[0];
    int min_ind = 0, max_ind = 0;
    
    for(int i = 0; i < length; i++){
        if (min > arr[i]){
            min = arr[i];
            min_ind = i;
        }
        if (max < arr[i]){
            max = arr[i];
            max_ind = i;
        }
    }
    arr[max_ind] = min;
    arr[min_ind] = max;
    for(int i = 0; i < length; i++)
        printf("%d ", arr[i]);
}
