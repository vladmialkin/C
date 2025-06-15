#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < length; i++)
        printf("%d ", arr[i] * -1);
}
