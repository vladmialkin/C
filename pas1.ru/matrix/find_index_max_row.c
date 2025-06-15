#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10


int main() {
    int matrix[ROWS][COLS];  
    int local_max;
    int max_ind_j = 0;   
    srand((unsigned) time(NULL));
    
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Двумерный массив:\n");
    for(int i = 0; i < ROWS; ++i) {
        local_max = matrix[i][0];
        max_ind_j = 0;
        for(int j = 0; j < COLS; ++j) {
            if (local_max < matrix[i][j]){
                local_max = matrix[i][j];
                max_ind_j = j;
            }
            printf("%4d", matrix[i][j]);
        }
        printf("\nindex max element: [%d][%d]", i, max_ind_j);
        printf("\n");  
    }
    return 0;
}
