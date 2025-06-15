#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {5, 2, -3, -4, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int pos_count = 0, neg_count = 0;

    for(int i = 0; i < length; i++){
        if (arr[i] > 0)
            pos_count += 1;
        else if (arr[i] < 0)
            neg_count += 1;
    }
    printf("count pos values: %d\n", pos_count);
    printf("count neg values: %d\n", neg_count);
}
