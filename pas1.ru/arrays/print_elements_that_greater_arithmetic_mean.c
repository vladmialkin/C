#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    float arith = 0;
    int sum = 0;

    for(int i = 0; i < length; i++){
        sum += arr[i];
    }
    arith = (float)sum / length;
    printf("arithmetic value: %0.2f, sum: %d, count: %d\n", arith, sum, length);
}
