#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10


int main() {
    int matrix[ROWS][COLS];  
    int sum[ROWS];
    int local_sum;
    int max_sum;
    int max_ind = 0;   
    srand((unsigned) time(NULL));
    
    for(int i = 0; i < COLS; ++i)
        sum[i] = 0;

    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Двумерный массив:\n");
    for(int i = 0; i < ROWS; ++i) {
        local_sum = 0;
        for(int j = 0; j < COLS; ++j) {
            local_sum += matrix[i][j]; 
            printf("%*d ", 3, matrix[i][j]);
        }
        sum[i] = local_sum;
        if (local_sum > max_sum){
            max_sum = local_sum;
            max_ind = i;
        }
        printf("\n");  
    }
    printf("\nrow: ");
    for(int i = 0; i < COLS; i++)
        printf("%d ", matrix[max_ind][i]);
    printf("\n");
    return 0;
}
